#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "estado.h"
#include "auxiliares.h"

ESTADO interfaceN (ESTADO e, char buffer [],STACK *s) {
    int i;
    e =reset(e);
    for (i = 0;buffer[i] == ' ' || buffer[i] == 'N' || buffer[i] == 'n';i++ );
    char c = buffer[i];
    if (c == 'X' || c == 'x') {
        e.peca = VALOR_X;
        printf("\n");
        printa(e);
        printf("\n");
    }
    else if (c == 'O' || c == 'o' ){
        e.peca = VALOR_O;
        printf("\n");
        printa(e);
        printf("\n");
    }
    else e.peca = VAZIA;
    initStack(e,s);
    return e;

}

ESTADO interfaceJ (ESTADO e, char buffer [],STACK *s){
    int i,l,cl;
    if (e.peca != VAZIA) {
        //Vai verificar se a peca foi colocada e se tal aconteceu vai avancar para o prox jogador
        for (i = 0; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        l = buffer[i] - 48;
        i++;
        for (; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        cl = buffer[i] - 48;
        if (possivelJogar(e, l, cl) == 0) printf("Jogada impossivel!!!!\n\n");
        else {
            //Vai executar a funcao e colocar uma peca no lugar
            e = jogar(e, buffer);
            e = substitui(e, l, cl);
            if (e.peca == VALOR_X) e.peca = VALOR_O;
            else e.peca = VALOR_X;
            push(e,s);
            printf("\n");
            printa(e);
            printf("\n");
        }
    }
    else printf("Ainda não começou o jogo !!!!\n\n");
    return e;
}

ESTADO interfaceJAux (ESTADO e) {
    if (acabou(e) == 0){
        if (conta (e,VALOR_X)>conta(e,VALOR_O) && e.grelha[4][4] != VAZIA) printf("************************\n**O Jogador *X* ganhou**\n************************\n\n");
        else if (conta (e,VALOR_X)<conta(e,VALOR_O) && e.grelha[4][4] != VAZIA) printf("************************\n**O Jogador *O* ganhou**\n************************\n\n");
        else if (conta (e,VALOR_X)==conta(e,VALOR_O) && e.grelha[4][4] != VAZIA)printf("************************\n*********Empate*********\n************************\n\n");
        e.peca = VAZIA;
        e = reset (e);
    }
    else if (podeJogar(e) == 0 && e.peca == VALOR_X) {
        printf("Jogador X não consegue jogar. Turno passa para jogador O");
        e.peca = VALOR_O;
    }
    else if (podeJogar(e) == 0 && e.peca == VALOR_O) {
        printf("Jogador O não consegue jogar. Turno passa para jogador X");
        e.peca = VALOR_X;
    }
    return  e;
}

void interfaceE(ESTADO e,char buffer[]) {
    FILE *fptr;
    int i = 2, j,l,c;
    char nome[100];
    char modo;
    char jogador;
    //for (i = 0; buffer[i] == 'E' || buffer[i] == 'e' || buffer[i] == ' '; i++);
    for (j = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++, j++) {
        if (buffer[i] == ' ') nome[j] = '_';
        else nome[j] = buffer[i];
    }
    nome[j] = '\0';
    strcat(nome, ".txt");
    fptr = fopen(nome,"w");
    if (e.modo == 0) modo = 'M';
    else modo = 'A';
    if (e.peca == VALOR_X) jogador = 'X';
    else if (e.peca == VALOR_O) jogador = 'O';
    else jogador = '?';
    fprintf(fptr,"%c %c\n",modo,jogador);
    for (l = 0;l<8;l++){
        for (c = 0;c<8;c++) {
            if (e.grelha[l][c] == VALOR_X) fprintf(fptr,"X ");
            else if (e.grelha[l][c] == VALOR_O) fprintf(fptr,"O ");
            else if (possivelJogar(e,l+1,c+1)) fprintf(fptr,". ");
            else fprintf(fptr,"- ");
        }
        fprintf(fptr,"\n");
    }
    fclose(fptr);
}

ESTADO interfaceL(ESTADO e,char buffer[]) {
    FILE *fptr;
    int i = 2, j,l = 0,c = 0;
    char nome[100];
    char linha[100];
    char modo;
    char jogador;
    //for (i = 0; buffer[i] == 'L' || buffer[i] == 'l' || buffer[i] == ' '; i++);
    for (j = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++, j++) {
        if (buffer[i] == ' ') nome[j] = '_';
        else nome[j] = buffer[i];
    }
    nome[j] = '\0';
    strcat(nome, ".txt");
    fptr = fopen(nome,"r");
    if (fptr == NULL) {printf("Não existe esse save!!!\n");return e;}
    fscanf(fptr,"%c %c",&modo,&jogador);
    if (jogador == 'X') e.peca = VALOR_X;
    else if (jogador == 'O') e.peca = VALOR_O;
    else e.peca = VAZIA;
    if (modo == 'M') e.modo = 0;
    else e.modo = 1;
    fseek(fptr,1,SEEK_CUR);
    for (i = 0;i<8;i++) {
        fgets(linha,100,fptr);
        c = 0;
        for (j = 0; linha[j] != '\n' && c < 8; j++) {
            if (linha[j] == 'X') {
                e.grelha[i][c] = VALOR_X;
                c++;
            }
            else if (linha[j] == 'O') {
                e.grelha[i][c] = VALOR_O;
                c++;
            }
            else if (linha[j] == '-' || linha[j] == '.'){
                e.grelha[i][c] = VAZIA;
                c++;
            }
        }
    }
    fclose(fptr);
    printf("\n");
    printa(e);
    printf("\n");
    return e;
}
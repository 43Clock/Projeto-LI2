#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "estado.h"
#include "auxiliares.h"

/**
 * @brief Esta função é utilizada para começar um novo jogo, sendo o primeiro jogador a jogar o que foi escolhido no input.
 * @param e Estado atual do jogo para que possa ser resetado e escolhido o primeiro jogador assim como o modo.
 * @param buffer Um array de caracteres correspondente ao input que se fez para executar esta função.
 * @param s Uma stack de listas ligadas para se registar as jogadas feita para que posteriormente seja possivel fazer undo às jogadas.
 * @return Retorna o novo estado de jogo com o proximo jogador a jogar.
 */
ESTADO interfaceN (ESTADO e, char buffer[],STACK *s) {
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
    e.modo  = '0';
    initStack(s);
    push(e,s);
    return e;

}

ESTADO interfaceA (ESTADO e, char buffer [],STACK *s,VALOR *bot) {
    int i;
    char d;
    e = reset(e);
    for (i = 0;buffer[i] == ' ' || buffer[i] == 'A' || buffer[i] == 'a';i++ );
    char c = buffer[i];
   // i++;
    //for (;buffer[i] == ' ';i++);
    //char d = buffer[i];
    if (c == 'X' || c == 'x') {
        *bot = VALOR_X;
        e.peca = VALOR_X;
        printf("\n");
        printa(e);
        printf("\n");
        e = jogaBot (e,3,4);
        e = substitui(e,3,4);
        e.peca = VALOR_O;
        printf("\n");
        printa(e);
        printf("\n");
    }
    else if (c == 'O' || c == 'o' ){
        *bot = VALOR_O;
        e.peca = VALOR_X;
        printf("\n");
        printa(e);
        printf("\n");
    }
    else e.peca = VAZIA;
    for (i = 0;buffer[i] == ' ' || toupper(buffer[i]) == 'A'|| toupper(buffer[i]) == 'X'|| toupper(buffer[i]) == 'O';i++);
    d = buffer[i];
    e.modo  = d;
    initStack(s);
    push(e,s);
    return e;

}

ESTADO interfaceJ (ESTADO e, char buffer [],STACK *s,POSICOES *p,VALOR *bot){
    int i,l,cl;
    if (e.peca != VAZIA) {
        if (e.modo == '0') {
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
                push(e, s);
                printf("\n");
                printa(e);
                printf("\n");
            }
        } else {
            for (i = 0; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
            l = buffer[i] - 48;
            i++;
            for (; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
            cl = buffer[i] - 48;
            if (possivelJogar(e, l, cl) == 0) printf("Jogada impossivel!!!!\n\n");
            else {
                e = jogar(e, buffer);
                e = substitui(e, l, cl);
                if (e.peca == VALOR_X) e.peca = VALOR_O;
                else e.peca = VALOR_X;
                printf("\n");
                printa(e);
                listaPosicoes(e,p);
                if (e.modo == '1') e = bot1(e, p);
                else e = bot2(e, e.modo, p);
                push(e, s);
            }
        }
    }
    else printf("Ainda não começou o jogo !!!!\n\n");
    return e;
}

ESTADO interfaceJAux (ESTADO e,VALOR *bot,POSICOES *p) {
    if (acabou(e) == 0){
        if (conta (e,VALOR_X)>conta(e,VALOR_O) && e.grelha[4][4] != VAZIA) printf("************************\n**O Jogador *X* ganhou**\n************************\n\n");
        else if (conta (e,VALOR_X)<conta(e,VALOR_O) && e.grelha[4][4] != VAZIA) printf("************************\n**O Jogador *O* ganhou**\n************************\n\n");
        else if (conta (e,VALOR_X)==conta(e,VALOR_O) && e.grelha[4][4] != VAZIA)printf("************************\n*********Empate*********\n************************\n\n");
        e.peca = VAZIA;
        e = reset (e);
    }
    else if (podeJogar(e) == 0 && e.peca == VALOR_X && e.modo > '0') {
        if (e.peca == *bot) {
            printf("O bot não consegue jogar. Turno passa para jogador O\n");
            e.peca = VALOR_O;
        }
        else {
            printf("O Jogador X não consegue jogar. Turno passado para o bot\n");
            e.peca = *bot;
            listaPosicoes(e, p);
            e = bot2(e, e.modo, p);
        }
    }
    else if (podeJogar(e) == 0 && e.peca == VALOR_O && e.modo > '0') {
        if (e.peca == *bot) {
            printf("O bot não consegue jogar. Turno passa para jogador O\n"); 
            e.peca = VALOR_X;
        }
        else {
            printf("O Jogador X não consegue jogar. Turno passado para o bot\n");
            e.peca = *bot;
            listaPosicoes(e, p);
            e = bot2(e, e.modo, p);
        }
    }
    else if (podeJogar(e) == 0 && e.peca == VALOR_O) {
        printf("Jogador O não consegue jogar. Turno passa para jogador X\n");
        e.peca = VALOR_X;
    }
    else if (podeJogar(e) == 0 && e.peca == VALOR_X){
        printf("Jogador X não consegue jogar. Turno passa para jogador X\n");
        e.peca = VALOR_O;
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
    fptr = fopen(nome,"w");
    if (e.modo == 0) modo = 'M';
    else modo = 'A';
    if (e.peca == VALOR_X) jogador = 'X';
    else if (e.peca == VALOR_O) jogador = 'O';
    else jogador = '?';
    if (modo == 'A') fprintf(fptr,"%c %c %c\n",modo,jogador,e.modo);
    else fprintf(fptr,"%c %c\n",modo,jogador);
    for (l = 0;l<8;l++){
        for (c = 0;c<8;c++) {
            if (e.grelha[l][c] == VALOR_X) fprintf(fptr,"X ");
            else if (e.grelha[l][c] == VALOR_O) fprintf(fptr,"O ");
            else fprintf(fptr,"- ");
        }
        fprintf(fptr,"\n");
    }
    fclose(fptr);
    printf("\nJogo guardado com sucesso!!\n");
}

ESTADO interfaceL(ESTADO e,char buffer[],VALOR *bot) {
    FILE *fptr;
    int i = 2, j,c = 0;
    char nome[100];
    char linha[100];
    char modo,bots;
    char jogador;
    //for (i = 0; buffer[i] == 'L' || buffer[i] == 'l' || buffer[i] == ' '; i++);
    for (j = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++, j++) {
        if (buffer[i] == ' ') nome[j] = '_';
        else nome[j] = buffer[i];
    }
    nome[j] = '\0';
    fptr = fopen(nome,"r");
    if (fptr == NULL) {printf("Não existe esse save!!!\n");return e;}
    fscanf(fptr,"%c ",&modo);
    if (modo == 'M'){
        fscanf(fptr,"%c",&jogador);
        if (jogador == 'X') e.peca = VALOR_X;
        else if (jogador == 'O') e.peca = VALOR_O;
        else e.peca = VAZIA;
        e.modo = '0';
    }
    else {
        fscanf(fptr,"%c %c",&jogador, &bots);
        *bot = bots;
        if (jogador == 'X') e.peca = VALOR_X;
        else if (jogador == 'O') e.peca = VALOR_O;
        else e.peca = VAZIA;
        e.modo = bots;

    }
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
            else if (linha[j] == '-'){
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
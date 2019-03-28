#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "estado.h"


void opcoes () {
    printf("N <peça> para começar um novo jogo.\n");
    printf("L <ficheiro> ler ficheiro de jogo.\n");
    printf("J <L,C> para fazer a jogada.\n");
    printf("S para mostrar as jogadas posiveis.\n");
    printf("H sugestão de jogada.\n");
    printf("U para desfazer a ultima jogada feita.\n");
    printf("A <peça> novo jogo contra 'bot'.\n");
    printf("Q para sair.\n");
}

ESTADO reset (ESTADO e) {
    int i,j;
    for (i = 0;i<8;i++)
        for (j = 0;j<8;j++)
            e.grelha[i][j] = VAZIA;
    return e;
}


int conta (ESTADO e,VALOR n) {
    int i,j,acc = 0;
    for (i = 0;i<8;i++)
        for (j = 0;j<8;j++) {
            if ((e.grelha[i][j] ) == n) acc++;
        }
    return acc;
}

ESTADO jogarX (ESTADO e,char s[]) {
    int l,c;
    int i;
    putchar('\n');
    for (i = 0;s[i] == 'j' || s[i] == 'J' ||s[i] == ' ' ;i++);
        l = s[i]-48;
        //printf("%d",l);
    i++;
    for (;s[i] == 'j' || s[i] == 'J' ||s[i] == ' ' ;i++);
        c = s[i]-48;
    if (l-1 >= 8 || c-1 >= 8 || e.grelha[l-1][c-1] != VAZIA){
        printf("Posição Invalida\n");
        //printf("%c",l);
        }
    else {
        e.grelha[l-1][c-1] = VALOR_X;
        printf("\n");
        printa(e);
        printf("\n");
        return e;
    }
}

ESTADO jogarO (ESTADO e,char s[]) {
    int l,c;
    int i;
    putchar('\n');
    for (i = 0;s[i] == 'j' || s[i] == 'J' ||s[i] == ' ' ;i++);
    l = s[i]-48;
    //printf("%d",l);
    i++;
    for (;s[i] == 'j' || s[i] == 'J' ||s[i] == ' ' ;i++);
    c = s[i]-48;
    if (l-1 >= 8 || c-1 >= 8 || e.grelha[l-1][c-1] != VAZIA){
        printf("Posição Invalida\n");
        printf("%c",l);
    }
    else {
        e.grelha[l-1][c-1] = VALOR_O;
        printf("\n");
        printa(e);
        printf("\n");
        return e;
    }
}

int possivelJogar (ESTADO e) { //0 == não é possivel jogar
    int i,j,r = 0;
    for (i = 0;i<8 && r == 0;i++)
        for (j = 0;j<8 && r == 0;j++)
            if (e.grelha[i][j] == VAZIA) r = 1;
    return r;

}
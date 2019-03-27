#include <stdio.h>
#include "auxiliares.h"
#include "estado.h"


int conta (ESTADO e,VALOR n) {
    int i,j,acc = 0;
    for (i = 0;i<8;i++)
        for (j = 0;j<8;j++) {
            if ((e.grelha[i][j] ) == n) acc++;
        }
    return acc;
}

ESTADO jogarX (ESTADO e) {
    int l,c;
    printf("\nTurno do jogador X. Escolher posição: ");
    scanf ("%d %d",&l,&c);
    putchar('\n');
    if (l-1 >= 8 || c-1 >=8 || e.grelha[l-1][c-1] != VAZIA)
        while (l-1 >= 8 || c-1 >=8 || e.grelha[l-1][c-1] != VAZIA) {
            printf("Posição Invalida.Tenta outra vez: ");
            scanf ("%d %d",&l,&c);
        }
    e.grelha[l-1][c-1] = VALOR_X;
    return e;
}

ESTADO jogarO (ESTADO e) {
    int l,c;
    printf("\nTurno do jogador O. Escolher posição: ");
    scanf ("%d %d",&l,&c);
    putchar('\n');
    if (l-1 >= 8 || c-1 >=8 || e.grelha[l-1][c-1] != VAZIA)
        while (l-1 >= 8 || c-1 >=8 || e.grelha[l-1][c-1] != VAZIA) {
            printf("\nPosição Invalida.Tenta outra vez: ");
            scanf ("%d %d",&l,&c);
        }
    e.grelha[l-1][c-1] = VALOR_O;
    return e;
}

int possivelJogar (ESTADO e) { //0 == não é possivel jogar
    int i,j,r = 0;
    for (i = 0;i<8 && r == 0;i++)
        for (j = 0;j<8 && r == 0;j++)
            if (e.grelha[i][j] == VAZIA) r = 1;
    return r;

}
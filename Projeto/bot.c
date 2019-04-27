#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "estado.h"
#include "auxiliares.h"

void listaPosicoes (ESTADO e,POSICOES *p) {
    int i,j;
    POSICAO pos;
    p->sp = 0;
    for (i = 0;i<8;i++)
        for (j = 0;j<8;j++)
            if (possivelJogar(e,i+1,j+1)) {
                pos.l = i+1;
                pos.c = j+1;
                p->valores[p->sp++] = pos;
            }
}


ESTADO jogaBot (ESTADO e,int l, int c) {
    if (l - 1 >= 8 || c - 1 >= 8 || e.grelha[l - 1][c - 1] != VAZIA) {
        printf("Posição Invalida\n");
    } else {
        e.grelha[l - 1][c - 1] = e.peca;
    }
    return e;
}

ESTADO bot1 (ESTADO e,POSICOES *p) {
    int j = p->sp;
    int l,c,i,pontos = -100,tmp;
    ESTADO aux;
    for (i = 0;i<j;i++) {
        tmp = 0;
        aux = e;
        aux = jogaBot(e,p->valores[i].l,p->valores[i].c);
        aux = substitui(e,p->valores[i].l,p->valores[i].c);
        tmp += conta(aux,e.peca)-conta(e,e.peca);
        if (pontos_pos(p->valores[i].l,p->valores[i].c)<0) tmp -= 10;
        else tmp += pontos_pos(p->valores[i].l,p->valores[i].c);
        if (tmp>pontos) {
            pontos = tmp;
            l = p->valores[i].l;
            c = p->valores[i].c;
        }
    }
    e = jogaBot(e,l,c);
    e = substitui(e, l, c);
    if (e.peca == VALOR_X) e.peca = VALOR_O;
    else e.peca = VALOR_X;
    printf("\nO bot jogou na posição : %d %d\n",l,c);
    printf("\n");
    printa(e);
    printf("\n");
    return e;
}

int pontos_pos (int l,int c) {
    int matrizPontos[8][8] = { {25, -5, 14, 10, 10, 14, -5, 25},
                               {-5, -7, -4,  1,  1, -4, -7, -5},
                               {14, -4,  3,  2,  2,  3, -4, 14},
                               {10,  1,  2, -6, -6,  2,  1, 10},
                               {10,  1,  2, -6, -6,  2,  1, 10},
                               {14, -4,  3,  2,  2,  3, -4, 14},
                               {-5, -7, -4,  1,  1, -4, -7, -5},
                               {25, -5, 14, 10, 10, 14, -5, 25}};
    return matrizPontos[l-1][c-1];
}
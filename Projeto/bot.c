#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "estado.h"
#include "auxiliares.h"
/**
 *
 * @param e - Estado atual do jogo
 * @param p - Array com todas as posições possiveis para o jogador em questão
 */
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

/**
 *
 * @param e - Estado atual do jogo
 * @param l - Linha onde vai jogar
 * @param c - Coluna onde vai jogar
 * @return - Estado depois da jogada
 */
ESTADO jogaBot (ESTADO e,int l, int c) {
    if (l - 1 >= 8 || c - 1 >= 8 || e.grelha[l - 1][c - 1] != VAZIA) {
        printf("Posição Invalida\n");
    } else {
        e.grelha[l - 1][c - 1] = e.peca;
    }
    return e;
}

/**
 *
 * @param e - Estado atual do jogo
 * @param p - Posições possiveis para o bot jogar
 * @return - Estado depois da jogada do bot
 */
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
/**
 * @brief - Matriz usada na heuristica do bot em que cada posição corresponde a uma pontuação
 * @param l - Linha
 * @param c - Coluna
 * @return - Valor da posição
 */
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

/**
 *
 * @param e - Estado atual do jogo
 * @param a - O jogador para o qual vai ser contado o numero de jogadas possiveis
 * @return - Quantidade de jogadas possiveis para o jogador
 */
int conta_mob (ESTADO e,VALOR a) {
    int i,j,r = 1; //Ver o erro que dava quando r = 0;
    e.peca = a;
    for (i = 0;i<8;i++) {
        for (j = 0; j < 8; j++) {
            if (possivelJogar(e, i + 1, j + 1) == 1) r++;
        }
    }
    return r;
}

/**
 *
 * @param e - Estado atual do jogo
 * @param depth - O quão fundo o bot vai analisar as jogadas possiveis.
 * @param original - A profundidade original
 * @param alfa - Variavel usada para fazer com que o bot faça o menor numero de verificações possiveis
 * @param beta - Variavel usada para fazer com que o bot faca o menor numero de verificacoes possiveis
 * @param p - Posiçoes onde pode jogar
 * @param bot - Valor do bot
 * @param final - Posicao final
 * @return
 */
int minmax (ESTADO e,int depth,int original,int alfa, int beta,POSICOES *p,VALOR bot,POSICAO *final) {
    VALOR v;
    ESTADO e_tmp;
    int max,min,i,aval;
    POSICOES s;

    if (bot == VALOR_X) v = VALOR_O;
    else v = VALOR_X;

    if (depth == 0) return pontos(e,bot);

    if (bot == e.peca) {
        max = -10000;
        e_tmp = e;
        for (i = 0;i<p->sp;i++) {
            e = e_tmp;
            e = jogaBot(e, p->valores[i].l, p->valores[i].c);
            e = substitui(e, p->valores[i].l, p->valores[i].c);
            if (e.peca == VALOR_X) e.peca = VALOR_O;
            else e.peca = VALOR_X;
            listaPosicoes(e, &s);
            aval = minmax(e, depth - 1,original,alfa,beta,&s, bot,final);
            if (aval > max) {
                max = aval;
                if (depth == original) {
                    final->l = p->valores[i].l;
                    final->c = p->valores[i].c;
                }
            if (aval > alfa) alfa = aval;
            if (beta <= alfa) break;
            }
            //printf("%d %d %d\n",max,final->l,final->c);
        }
        return max;
    }
    else {
        min = 10000;
        e_tmp = e;
        for (i = 0;i<p->sp;i++) {
            e = e_tmp;
            e = jogaBot(e, p->valores[i].l, p->valores[i].c);
            e = substitui(e, p->valores[i].l, p->valores[i].c);
            if (e.peca == VALOR_X) e.peca = VALOR_O;
            else e.peca = VALOR_X;
            listaPosicoes(e, &s);
            aval = minmax(e, depth - 1,original,alfa,beta, &s, bot,final);
            if (aval < min) min = aval;
            if (aval < beta) beta = aval;
            if (beta<= alfa) break;
        }
        return min;
    }
}

/**
 *
 * @param e - Estado atual do jogo
 * @param bot - Valor do bot
 * @return
 */


// Falta return

int pontos(ESTADO e,VALOR bot) {
    VALOR v;
    int i,j,h1 = 0,h2 = 0,h3 = 0;
    if (bot == VALOR_X) v = VALOR_O;
    else v = VALOR_X;
    for (i = 0;i<8;i++)
        for (j = 0 ;j<8;j++) {
            if (e.grelha[i][j] == bot) h1 += pontos_pos(i+1,j+1);
            else if (e.grelha[i][j] == v) h1 -= pontos_pos(i+1,j+1);
        }
    h2 = (conta(e,bot)-conta(e,v))/(conta(e,bot)+conta(e,v));
    h3 = (conta_mob(e,bot)-conta_mob(e,v))/(conta_mob(e,bot)+conta_mob(e,v));
    return h1+50*h2+100*h3;
}
/**
 *
 * @param e - Estado  atual do jogo
 * @param c
 * @param p
 * @return
 */
ESTADO bot2 (ESTADO e,char c,POSICOES *p) {
    POSICAO final;
    int cd = c - '0';
    int r;
    r = minmax(e, (cd * 2) + 1, (cd * 2) + 1,-100000,100000, p, e.peca, &final);
    e = jogaBot(e, final.l, final.c);
    e = substitui(e, final.l, final.c);
    if (e.peca == VALOR_X) e.peca = VALOR_O;
    else e.peca = VALOR_X;
    printf("\nO bot jogou na posição : %d %d\n", final.l, final.c);
    printf("\n");
    printa(e);
    printf("\n");
    return e;
}
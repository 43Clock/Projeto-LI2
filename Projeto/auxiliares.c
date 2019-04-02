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
    }
    return e;
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
        //printf("%c",l);
    }
    else {
        e.grelha[l-1][c-1] = VALOR_O;
    }
    return e;
}

int possivelJogar (ESTADO e,int valor, int l, int c) { //0 == não é possivel jogar
    int i,r = 0;
    int li = l-1;
    int ci = c-1;
    for (i = 1;i<9 && r == 0;i++) {
        switch (i) {
            case 1:
                if (valor == 1) {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li-1][ci] != VALOR_X && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                }
                else {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li-1][ci] != VALOR_O && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                }
                break;

            case 2:
                if (valor == 1) {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li-1][ci+1] != VALOR_X && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                    break;
                }
                else {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li-1][ci+1] != VALOR_O && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                }
            break;

            case 3:
                if (valor == 1) {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li][ci+1] != VALOR_X && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                    break;
                }
                else {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li][ci+1] != VALOR_O && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                }
            break;

            case 4:
                if (valor == 1) {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li+1][ci+1] != VALOR_X && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                    break;
                }
                else {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li+1][ci+1] != VALOR_O && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                }
            break;

            case 5:
                if (valor == 1) {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li+1][ci] != VALOR_X && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                    break;
                }
                else {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li+1][ci] != VALOR_O && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                }
            break;
            case 6:
                if (valor == 1) {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li+1][ci-1] != VALOR_X && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                    break;
                }
                else {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li+1][ci-1] != VALOR_O && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                }
            break;
            case 7:
                if (valor == 1) {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li][ci-1] != VALOR_X && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                    break;
                }
                else {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li][ci-1] != VALOR_O && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                }
            break;
            case 8:
                if (valor == 1) {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li-1][ci-1] != VALOR_X && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                    break;
                }
                else {
                    if (e.grelha[li][ci] == VAZIA && e.grelha[li-1][ci-1] != VALOR_O && substituiAux(e,i,valor,l,c) == i)
                        r = 1;
                }
            break;
        }
    }
    return r;
}


void helpPlz (ESTADO e, int valor) {
    int i,j;
    putchar ('\n');
    for (i = 0;i<8;i++) {
        for (j = 0; j < 8; j++) {
            if (e.grelha[i][j] == VALOR_X) printf("X ");
            else if (e.grelha[i][j] == VALOR_O) printf("O ");
            else {
                if (possivelJogar(e, valor, i + 1, j + 1) == 0) printf("- ");
                else printf(". ");
            }
        }
        putchar('\n');
    }
}
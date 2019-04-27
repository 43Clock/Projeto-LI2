#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "estado.h"


void opcoes () {
    printf("\nN <peça> para começar um novo jogo.\n");
    printf("L <ficheiro> ler ficheiro de jogo.\n");
    printf("E <ficheiro> para escrever ficheiro de jogo\n");
    printf("J <L,C> para fazer a jogada.\n");
    printf("S para mostrar as jogadas posiveis.\n");
    printf("H sugestão de jogada.\n");
    printf("U para desfazer a ultima jogada feita.\n");
    printf("A <peça> <nivel> novo jogo contra 'bot'.\n");
    printf("Q para sair.\n\n");
}

ESTADO reset (ESTADO e){
    int i,j;
    for (i = 0;i<8;i++)
        for (j = 0;j<8;j++)
            e.grelha[i][j] = VAZIA;
    e.grelha[3][4] = VALOR_O;
    e.grelha[4][3] = VALOR_O;
    e.grelha[3][3] = VALOR_X;
    e.grelha[4][4] = VALOR_X;
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

ESTADO jogar (ESTADO e,char s[]) {
    int l,c;
    int i;
    putchar('\n');
    for (i = 0;s[i] == 'j' || s[i] == 'J' ||s[i] == ' ' ;i++);
    l = s[i]-48;
    i++;
    for (;s[i] == 'j' || s[i] == 'J' ||s[i] == ' ' ;i++);
    c = s[i]-48;
    if (l-1 >= 8 || c-1 >= 8 || e.grelha[l-1][c-1] != VAZIA){
        printf("Posição Invalida\n");
    }
    else {
        e.grelha[l-1][c-1] = e.peca;
    }
    return e;
}

int possivelJogar (ESTADO e,int l, int c) { //0 == não é possivel jogar
    int i,r = 0;
    int li = l-1;
    int ci = c-1;
    for (i = 1;i<9 && r == 0;i++) {
        switch (i) {
            case 1:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li-1][ci] != e.peca && substituiAux(e,i,l,c) == i)
                    r = 1;
                break;

            case 2:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li-1][ci+1] != e.peca && substituiAux(e,i,l,c) == i)
                    r = 1;
                break;

            case 3:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li][ci+1] != e.peca && substituiAux(e,i,l,c) == i)
                    r = 1;
                break;

            case 4:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li+1][ci+1] != e.peca && substituiAux(e,i,l,c) == i)
                    r = 1;
                break;

            case 5:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li+1][ci] != e.peca && substituiAux(e,i,l,c) == i)
                    r = 1;
            break;

            case 6:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li+1][ci-1] != e.peca && substituiAux(e,i,l,c) == i)
                    r = 1;
            break;

            case 7:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li][ci-1] != e.peca && substituiAux(e,i,l,c) == i)
                    r = 1;
                break;

            case 8:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li-1][ci-1] != e.peca && substituiAux(e,i,l,c) == i)
                    r = 1;
                break;
        }
    }
    return r;
}


void helpPlz (ESTADO e) {
    int i,j;
    putchar ('\n');
    printf("  1 2 3 4 5 6 7 8\n");
    for (i = 0;i<8;i++) {
        printf("%d ",i+1);
        for (j = 0; j < 8; j++) {
            if (e.grelha[i][j] == VALOR_X) printf("X ");
            else if (e.grelha[i][j] == VALOR_O) printf("O ");
            else {
                if (possivelJogar(e, i + 1, j + 1) == 0) printf("- ");
                else printf(". ");
            }
        }
        putchar('\n');
    }
    putchar('\n');
}

void helpPlz2 (ESTADO e) { // sugestão de jogada
    int i,j, r = 0;
    putchar ('\n');
    printf("  1 2 3 4 5 6 7 8\n");
    for (i = 0;i<8;i++) {
        printf("%d ",i+1);
        for (j = 0; j < 8; j++) {
            if (e.grelha[i][j] == VALOR_X) printf("X ");
            else if (e.grelha[i][j] == VALOR_O) printf("O ");
            else {
                if (possivelJogar(e, i + 1, j + 1) == 1 && r == 0){
                    printf("? ");
                    r++;
                }
                else printf("- ");
            }
        }
        putchar('\n');
    }
    putchar('\n');
}

void helpPlz2 (ESTADO e) {
    int i,j,r = 0;
    putchar ('\n');
    printf("  1 2 3 4 5 6 7 8\n");
    for (i = 0;i<8;i++) {
        printf("%d ",i+1);
        for (j = 0; j < 8; j++) {
            if (e.grelha[i][j] == VALOR_X) printf("X ");
            else if (e.grelha[i][j] == VALOR_O) printf("O ");
            else {
                if (possivelJogar(e, i + 1, j + 1) == 1 && r == 0) {
                    printf("? ");
                    r++;
                }
                else printf("- ");
            }
        }
        putchar('\n');
    }
}

int acabou (ESTADO e) { // 0 == não ha jogadas possiveis
    int r = 0;
    int i,j;
    e.peca = VALOR_X;
    for (i = 0;i<8 && r == 0;i++)
        for (j = 0;j<8 && r == 0;j++)
            if (possivelJogar(e, i + 1, j + 1)) {
                r++;
            }
    e.peca = VALOR_O;
    for (i = 0;i<8 && r == 0;i++)
        for (j = 0;j<8 && r == 0;j++)
            if (possivelJogar(e, i + 1, j + 1)) {
                r++;
            }
    return r;
}

int podeJogar (ESTADO e) {
    int r = 0;
    int i,j;
    for (i = 0;i<8 && r == 0;i++)
        for (j = 0;j<8 && r == 0;j++)
            if  (possivelJogar(e,i+1,j+1)) r = 1;
    return  r;
}

void initStack (ESTADO e,STACK *s) {
    *s = NULL;
}

int isEmpty (STACK *s) {
    return (*s == NULL || (*s) -> ant == NULL);
}

void push (ESTADO e,STACK *s) {
    STACK novo = (STACK) malloc(sizeof(struct stack));
    novo -> e = e;
    novo -> ant = *s;
    *s = novo;
}

ESTADO pop (ESTADO e,STACK *s) {
    STACK aux = *s;
    aux = aux -> ant;
    e = aux -> e;
    *s = aux;
    printf("\n");
    printa(e);
    printf("\n");
    return e;
}


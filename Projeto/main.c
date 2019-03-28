#include <stdio.h>
#include <ctype.h>
#include "estado.h"
#include "auxiliares.h"


ESTADO interface (ESTADO e) {
    char n;
    int i;
    char buffer[100];
    fgets(buffer,100,stdin);
    n = buffer[0];
    switch (toupper(n)) {
        case 'N':
            e = reset(e);
            e.grelha[3][4] = VALOR_O;
            e.grelha[4][3] = VALOR_O;
            e.grelha[3][3] = VALOR_X;
            e.grelha[4][4] = VALOR_X;
            printf("\n");
            printa(e);
            printf("\n");
            break;

        case 'J':
            e = jogarX(e,buffer);
            printf("\n");
            printa(e);
            printf("\n");
            break;



    }
    return e;
}


int main() {
    ESTADO e = {0};
    while (1){
        printf("Reversi > ");
        e = interface(e);
    }
}
/*
    // estado inicial do tabuleiro. Inicio do jogo!
    e.grelha[3][4] = VALOR_O;
    e.grelha[4][3] = VALOR_O;
    e.grelha[3][3] = VALOR_X;
    e.grelha[4][4] = VALOR_X;
    //e.grelha[2][2] = VALOR_X;

    printf("\n");
    printa(e);
    printf("\n");


    if (c == 'X') {
        while (possivelJogar(e) == 1) {
            e = jogarX(e);
            printa(e);
            printf("\nPontuação do jogador O: %d\n", conta(e, VALOR_O));
            printf("Pontuação do jogador X: %d\n", conta(e, VALOR_X));
            e = jogarO(e);
            printa(e);
            printf("\nPontuação do jogador O: %d\n", conta(e, VALOR_O));
            printf("Pontuação do jogador X: %d\n", conta(e, VALOR_X));
        }
    }
    else {
        while (possivelJogar(e) == 1) {
            e = jogarO(e);
            printa(e);
            printf("\nPontuação do jogador O: %d\n", conta(e, VALOR_O));
            printf("Pontuação do jogador X: %d\n", conta(e, VALOR_X));
            e = jogarX(e);
            printa(e);
            printf("\nPontuação do jogador O: %d\n", conta(e, VALOR_O));
            printf("Pontuação do jogador X: %d\n", conta(e, VALOR_X));
        }

    }

    if (conta (e,VALOR_X) > conta(e,VALOR_O)) printf("\nJogador X ganhou.\n");
    if (conta (e,VALOR_X) < conta(e,VALOR_O)) printf("\nJogador O ganhou.\n");
    if (conta (e,VALOR_X) > conta(e,VALOR_O)) printf("\nEmpate.\n");

    //printf("\n");
    //printa(e);
    //printf("\n");


    return 0;
}*/
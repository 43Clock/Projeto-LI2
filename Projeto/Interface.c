#include <stdio.h>
#include <ctype.h>
#include "estado.h"
#include "auxiliares.h"

ESTADO interfaceN (ESTADO e, char buffer []) {
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
    return e;

}

ESTADO interfaceJ (ESTADO e, char buffer []){
    int i,l,cl;
    if (e.peca == VALOR_X) {
        //Vai verificar se a peca foi colocada e se tal aconteceu vai avancar para o prox jogador
        for (i = 0; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        l = buffer[i] - 48;
        i++;
        for (; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        cl = buffer[i] - 48;
        if (possivelJogar(e, l, cl) == 0) printf("Jogada impossivel!!!!\n\n");
        else {
            //Vai executar a funcao e colocar uma peca no lugar
            e = jogarX(e, buffer);
            e = substitui(e, l, cl);
            e.peca = VALOR_O;
            printf("\n");
            printa(e);
            printf("\n");
        }
    }

    else if (e.peca == VALOR_O) {
        for (i = 0; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        l = buffer[i] - 48;
        i++;
        for (; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        cl = buffer[i] - 48;
        if (possivelJogar(e, l, cl) == 0) printf("Jogada impossivel!!!!\n\n");
        else {
            e = jogarO(e, buffer);
            e = substitui(e, l, cl);
            e.peca = VALOR_X;
            printf("\n");
            printa(e);
            printf("\n");
        }
    }
    else printf("Ainda não começou o jogo !!!!\n\n");
    return e;
}
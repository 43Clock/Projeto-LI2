#include <stdio.h>
#include <ctype.h>
#include "estado.h"
#include "auxiliares.h"

int interfaceN (ESTADO e, char buffer []) {
    int i,valor;
    for (i = 0;buffer[i] == ' ' || buffer[i] == 'N' || buffer[i] == 'n';i++ );
    char c = buffer[i];
    if (c == 'X' || c == 'x') {
        valor = 1;
        printf("\n");
        printa(e);
        printf("\n");
    }
    else if (c == 'O' || c == 'o' ){
        valor = 2;
        printf("\n");
        printa(e);
        printf("\n");
    }
    else valor = 0;
    return valor;

}

ESTADO interfaceJE (ESTADO e, char buffer [],int valor){
    int i,l,cl;
    if (valor == 1) valor++;
    else valor--;
    if (valor == 1) {
        //Vai verificar se a peca foi colocada e se tal aconteceu vai avancar para o prox jogador
        for (i = 0; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        l = buffer[i] - 48;
        i++;
        for (; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        cl = buffer[i] - 48;
        if (possivelJogar(e, valor, l, cl) == 0) printf("Jogada impossivel!!!!\n\n");
        else {
            //Vai executar a funcao e colocar uma peca no lugar
            valor = 2;
            e = jogarX(e, buffer);
            e = substitui(e, valor - 1, l, cl);
            printf("\n");
            printa(e);
            printf("\n");
        }
    }

    else if (valor == 2) {
        for (i = 0; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        l = buffer[i] - 48;
        i++;
        for (; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        cl = buffer[i] - 48;
        if (possivelJogar(e, valor, l, cl) == 0) printf("Jogada impossivel!!!!\n\n");
        else {
            valor = 1;
            e = jogarO(e, buffer);
            e = substitui(e, valor + 1, l, cl);
            printf("\n");
            printa(e);
            printf("\n");
        }
    }
    else printf("Ainda não começou o jogo !!!!\n\n");
    return e;
}

int interfaceJV (ESTADO e, char buffer [],int valor){
    int i,l,cl;
    if (valor == 1) {
        //Vai verificar se a peca foi colocada e se tal aconteceu vai avancar para o prox jogador
        for (i = 0; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        l = buffer[i] - 48;
        i++;
        for (; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        cl = buffer[i] - 48;
        if (possivelJogar(e, valor, l, cl) == 0) printf("Jogada impossivel!!!!\n\n");
        else {
            //Vai executar a funcao e colocar uma peca no lugar
            valor = 2;
        }
    }

    else if (valor == 2) {
        for (i = 0; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        l = buffer[i] - 48;
        i++;
        for (; buffer[i] == 'j' || buffer[i] == 'J' || buffer[i] == ' '; i++);
        cl = buffer[i] - 48;
        if (possivelJogar(e, valor, l, cl) == 0) printf("Jogada impossivel!!!!\n\n");
        else {
            valor = 1;
        }
    }
    return valor;
}
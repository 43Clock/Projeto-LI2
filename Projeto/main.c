#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "estado.h"
#include "auxiliares.h"


ESTADO interface (ESTADO e) {
    char n;
    char buffer[100];
    fgets(buffer,100,stdin);
    n = buffer[0];
    switch (toupper(n)) {
        case 'N':
            e = interfaceN(e,buffer);
            break;

        case 'J':
            e = interfaceJ (e,buffer);
            e = interfaceJAux(e);
           break;
        case 'S':
            helpPlz(e);
            break;
        case 'E':
            interfaceE(e,buffer);
            break;
        case 'Q':
            exit(0);


    }
    return e;
}


void print_prompt(ESTADO e) {
    switch (e.peca) {
        case VALOR_X:
            printf("Reversi X > ");
            break;
        case VALOR_O:
            printf("Reversi O > ");
            break;
        default:
            printf("Reversi ? > ");
    }
}

int main() {
    ESTADO e = {0};
    opcoes();
    while (1){
        print_prompt(e);
        e = interface(e);
    }
}
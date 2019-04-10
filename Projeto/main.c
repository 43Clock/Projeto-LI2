#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "estado.h"
#include "auxiliares.h"


ESTADO interface (ESTADO e, STACK *s) {
    char n;
    int i;
    char buffer[100];
    fgets(buffer,100,stdin);
    n = buffer[0];
    switch (toupper(n)) {
        case 'N':
            e = interfaceN(e,buffer,s);
            break;

        case 'J':
            e = interfaceJ (e,buffer,s);
            e = interfaceJAux(e);
           break;
        case 'S':
            helpPlz(e);
            break;
        case 'H':
            helpPlz2(e);
            break;
        case 'E':
            interfaceE(e,buffer);
            break;
        case 'L':
            e = interfaceL(e,buffer);
            break;
        case 'U':
            if (isEmpty(s) == 0) e = pop(e,s);
            else printf("Não é possivel reverte a jogada!!!!!\n\n");
            break;
        default:
            printf("Comando Inválido\n");
            break;
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
    STACK s;
    while (1){
        print_prompt(e);
        e = interface(e,&s);
    }
}
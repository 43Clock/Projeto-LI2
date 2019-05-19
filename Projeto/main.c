#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "estado.h"
#include "auxiliares.h"



ESTADO interface (ESTADO e, STACK *s,POSICOES *p) {
    char n;
    char buffer[100];
    fgets(buffer,100,stdin);
    n = buffer[0];
    VALOR bot;
    POSICAO final;
    switch (toupper(n)) {
        case 'N':
            e = interfaceN(e,buffer,s);
            break;

        case 'J':
            e = interfaceJ (e,buffer,s,p,&bot);
            e = interfaceJAux(e,&bot,p);
           break;
        case 'S':
            helpPlz(e);
            break;
        case 'H':
            if (e.peca == VAZIA) printf("Ainda não começou o jogo !!!!\n\n");
            else {
                listaPosicoes(e, p);
                minmax(e, 7, 7, -100000, 100000, p, e.peca, &final);
                helpPlz2(e, final.l, final.c);
            }
            break;
        case 'E':
            interfaceE(e,buffer);
            break;
        case 'L':
            e = interfaceL(e,buffer,&bot);
            initStack(s);
            push(e,s);
            break;
        case 'U':
            if (isEmpty(s) == 0) e = pop(e,s);
            else printf("Não é possivel reverte a jogada!!!!!\n\n");
            break;
        case 'A':
            e = interfaceA(e,buffer,s,&bot);
            break;
        case 'Q':
            exit(0);
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
    STACK s =NULL;
    POSICOES p;
    while (1){
        print_prompt(e);
        e = interface(e,&s,&p);
    }
}
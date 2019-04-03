#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "estado.h"
#include "auxiliares.h"


ESTADO interface (ESTADO e) {
    char n;
    int i = 0;
    int l,cl;
    static int valor;
    char buffer[100];
    fgets(buffer,100,stdin);
    n = buffer[0];
    switch (toupper(n)) {
        case 'N':
            e = reset(e);
            valor = interfaceN(e,buffer);
            break;

        case 'J':
            valor = interfaceJV (e,buffer,valor);
            e = interfaceJE (e,buffer,valor);
           break;
        case 'H':
            helpPlz(e,valor);
            break;
        case 'Q':
            exit(0);


    }
    return e;
}


int main() {
    ESTADO e = {0};
    opcoes();
    while (1){
        printf("Reversi > ");
        e = interface(e);
    }
}
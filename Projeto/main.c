#include <stdio.h>
#include <ctype.h>
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
            for (i = 0;buffer[i] == ' ' || buffer[i] == 'N' || buffer[i] == 'n';i++ );
            char c = buffer[i];
            if (c == 'X' || c == 'x') valor = 1;
            else valor = 2;
            e.grelha[3][4] = VALOR_O;
            e.grelha[4][3] = VALOR_O;
            e.grelha[3][3] = VALOR_X;
            e.grelha[4][4] = VALOR_X;
            printf("\n");
            printa(e);
            printf("\n");
            break;

        case 'J':
            if (valor == 1) {

                //Vai verificar se a peca foi colocada e se tal aconteceu vai avancar para o prox jogador
                for (i = 0;buffer[i] == 'j' || buffer[i] == 'J' ||buffer[i] == ' ' ;i++);
                l = buffer[i]-48;
                i++;
                for (;buffer[i] == 'j' || buffer[i] == 'J' ||buffer[i] == ' ' ;i++);
                cl = buffer[i]-48;
                if (e.grelha[l-1][cl-1] == VAZIA) valor = 2;

                //Vai executar a funcao e colocar uma peca no lugar
                e = jogarX(e,buffer);
                e = substitui(e,valor-1,l,cl);
                printf("\n");
                printa(e);
                printf("\n");
            }
            else if (valor == 2) {
                for (i = 0;buffer[i] == 'j' || buffer[i] == 'J' ||buffer[i] == ' ' ;i++);
                l = buffer[i]-48;
                i++;
                for (;buffer[i] == 'j' || buffer[i] == 'J' ||buffer[i] == ' ' ;i++);
                cl = buffer[i]-48;
                if (e.grelha[l-1][cl-1] == VAZIA) valor = 1;
                e = jogarO(e,buffer);
                e = substitui(e,valor+1,l,cl);
                printf("\n");
                printa(e);
                printf("\n");
            }
            else printf("Ainda não começou o jogo !!!!\n\n");
            break;
        case ':


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

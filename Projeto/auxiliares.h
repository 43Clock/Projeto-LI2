#include "estado.h"

#ifndef PROJ_AUXILIARES_H
#define PROJ_AUXILIARES_H


typedef struct stack {
    int sp;
    ESTADO valores[100];
}STACK;


void opcoes ();
int conta (ESTADO e,VALOR n);
ESTADO jogar(ESTADO e,char s[]);
int possivelJogar (ESTADO e,int l, int c);
ESTADO reset (ESTADO e);
ESTADO substitui (ESTADO e,int l, int c);
int substituiAux (ESTADO e,int dir,int l,int c);
ESTADO interfaceN (ESTADO e, char buffer [],STACK *s);
ESTADO interfaceJ (ESTADO e, char buffer [],STACK *s);
ESTADO interfaceJAux (ESTADO e);
void interfaceE(ESTADO e,char buffer[]);
ESTADO interfaceL(ESTADO e,char buffer[]);
int acabou(ESTADO e);

int podeJogar (ESTADO e);

void helpPlz (ESTADO e);
void helpPlz2 (ESTADO e);

        void initStack (ESTADO e,STACK *s);
int isEmpty (STACK *s);
void push (ESTADO e,STACK *s);
ESTADO pop (ESTADO e,STACK *s);

#endif //PROJ_AUXILIARES_H

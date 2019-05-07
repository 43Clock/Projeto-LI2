#include "estado.h"

#ifndef PROJ_AUXILIARES_H
#define PROJ_AUXILIARES_H


typedef struct stack {
    ESTADO e;
    struct stack *ant;
}*STACK;

typedef struct posicao {
    int l;
    int c;
}POSICAO;

typedef struct posicoes {
    int sp;
    POSICAO valores[20];
}POSICOES;


//Funçoes para fazer os comandos
ESTADO interfaceN (ESTADO e, char buffer [],STACK *s);
ESTADO interfaceJ (ESTADO e, char buffer [],STACK *s,POSICOES *p,VALOR *bot);
ESTADO interfaceJAux (ESTADO e,VALOR *bot,POSICOES *p);
ESTADO interfaceA (ESTADO e, char buffer [],STACK *s,VALOR *bot);
ESTADO interfaceL(ESTADO e,char buffer[],VALOR *bot);
void interfaceE(ESTADO e,char buffer[]);
void helpPlz (ESTADO e);
void helpPlz2 (ESTADO e,int l, int c);


//Funcoes auxiliares
void opcoes ();
int conta (ESTADO e,VALOR n);
ESTADO jogar(ESTADO e,char s[]);
int possivelJogar (ESTADO e,int l, int c);
ESTADO reset (ESTADO e);
ESTADO substitui (ESTADO e,int l, int c);
int substituiAux (ESTADO e,int dir,int l,int c);
int acabou(ESTADO e);
int podeJogar (ESTADO e);


//Funcoes da stack
void initStack (STACK *s);
int isEmpty (STACK *s);
void push (ESTADO e,STACK *s);
ESTADO pop (ESTADO e,STACK *s);


//Funcoes do bot
ESTADO bot1 (ESTADO e,POSICOES *p);
ESTADO jogaBot (ESTADO e,int l, int c);
void listaPosicoes (ESTADO e,POSICOES *p);
int pontos_pos (int l,int c);
int pontos(ESTADO e,VALOR bot);
ESTADO bot2 (ESTADO e,char c,POSICOES *p);
int minmax (ESTADO e,int depth,int original,int alfa, int beta,POSICOES *p,VALOR bot,POSICAO *final);
int conta_mob (ESTADO e,VALOR a);

#endif //PROJ_AUXILIARES_H

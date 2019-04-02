#include "estado.h"

#ifndef PROJ_AUXILIARES_H
#define PROJ_AUXILIARES_H


int conta (ESTADO e,VALOR n);
ESTADO jogarX(ESTADO e,char s[]);
ESTADO jogarO(ESTADO e,char s[]);
int possivelJogar (ESTADO e,int valor, int l, int c);
ESTADO reset (ESTADO e);
ESTADO substitui (ESTADO e,int peca,int l, int c);
int substituiAux (ESTADO e,int dir,int jog,int l,int c);
void helpPlz (ESTADO e, int valor);

#endif //PROJ_AUXILIARES_H

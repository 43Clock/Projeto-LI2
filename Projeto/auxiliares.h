#include "estado.h"

#ifndef PROJ_AUXILIARES_H
#define PROJ_AUXILIARES_H


void opcoes ();
int conta (ESTADO e,VALOR n);
ESTADO jogarX(ESTADO e,char s[]);
ESTADO jogarO(ESTADO e,char s[]);
int possivelJogar (ESTADO e,int l, int c);
ESTADO reset (ESTADO e);
ESTADO substitui (ESTADO e,int l, int c);
int substituiAux (ESTADO e,int dir,int l,int c);
ESTADO interfaceN (ESTADO e, char buffer []);
ESTADO interfaceJ (ESTADO e, char buffer []);

void helpPlz (ESTADO e);

#endif //PROJ_AUXILIARES_H

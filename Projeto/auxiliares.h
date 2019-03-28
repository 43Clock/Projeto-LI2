#include "estado.h"

#ifndef PROJ_AUXILIARES_H
#define PROJ_AUXILIARES_H


int conta (ESTADO e,VALOR n);
ESTADO jogarX(ESTADO e,char s[]);
ESTADO jogarO(ESTADO e,char s[]);
int possivelJogar(ESTADO e);
ESTADO reset (ESTADO e);

#endif //PROJ_AUXILIARES_H

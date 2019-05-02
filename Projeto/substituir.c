#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "estado.h"

int substituiAux (ESTADO e,int dir,int l,int c) {
    int li = l - 1;
    int ci = c - 1;
    VALOR v;
    if (e.peca == VALOR_X) v = VALOR_O;
    else v = VALOR_X;
    switch (dir) {
        case 1:
            li--;
            if (e.grelha[li][ci] != v) return 0;
            while (li > -1) {
                if (e.grelha[li][ci] == VAZIA) return 0;
                if (e.grelha[li][ci] == e.peca) return 1;
                if (e.grelha[li][ci] == v) li--;
            }
            return 0;
        case 2:
            li--;
            ci++;
            if (e.grelha[li][ci] != v) return 0;
            while (li > -1 && ci < 8) {
                if (e.grelha[li][ci] == VAZIA) return 0;
                if (e.grelha[li][ci] == e.peca) return 2;
                if (e.grelha[li][ci] == v) {
                    li--;
                    ci++;
                }
            }
            return 0;

        case 3:
            ci++;
            if (e.grelha[li][ci] != v) return 0;
            while (ci < 8) {
                if (e.grelha[li][ci] == VAZIA) return 0;
                if (e.grelha[li][ci] == e.peca) return 3;
                if (e.grelha[li][ci] == v) ci++;
            }
            return 0;
        case 4:
            li++;
            ci++;
            if (e.grelha[li][ci] != v) return 0;
            if (li == 8 || ci == 8) return 0;
            while (li < 8 && ci < 8) {
                if (e.grelha[li][ci] == VAZIA) return 0;
                if (e.grelha[li][ci] == e.peca) return 4;
                if (e.grelha[li][ci] == v) {
                    li++;
                    ci++;
                }
            }
            return 0;
        case 5:
            li++;
            if (e.grelha[li][ci] != v) return 0;
            if (li == 8) return 0;
            while (li < 8) {
                if (e.grelha[li][ci] == VAZIA) return 0;
                if (e.grelha[li][ci] == e.peca) return 5;
                if (e.grelha[li][ci] == v) li++;
            }
            return 0;
        case 6:
            li++;
            ci--;
            if (e.grelha[li][ci] != v) return 0;
            if (li == 7 || ci == 0) return 0;
            while (li < 8 && ci < 8) {
                if (e.grelha[li][ci] == VAZIA) return 0;
                if (e.grelha[li][ci] == e.peca) return 6;
                if (e.grelha[li][ci] == v) {
                    li++;
                    ci--;
                }
            }
            return 0;
        case 7:
            ci--;
            if (e.grelha[li][ci] != v) return 0;
            while (ci > -1) {
                if (e.grelha[li][ci] == VAZIA) return 0;
                if (e.grelha[li][ci] == e.peca) return 7;
                if (e.grelha[li][ci] == v) ci--;
            }
            return 0;
        case 8:
            li--;
            ci--;
            if (e.grelha[li][ci] != v) return 0;
            while (li > -1 && ci > -1) {
                if (e.grelha[li][ci] == VAZIA) return 0;
                if (e.grelha[li][ci] == e.peca) return 8;
                if (e.grelha[li][ci] == v) {
                    li--;
                    ci--;
                }
            }
            return 0;

    }
}


ESTADO substitui (ESTADO e,int l, int c) {
    int li, ci, i;
    for (i = 1; i < 9; i++) {
        li = l - 1;
        ci = c - 1;
        if (substituiAux(e, i,l, c) == i) {
            switch (i) {
                case 1:
                    li--;
                    if (e.peca == VALOR_X) {
                        while (e.grelha[li][ci] != VALOR_X) {
                            e.grelha[li][ci] = VALOR_X;
                            li--;
                        }
                    } else
                        while (e.grelha[li][ci] != VALOR_O) {
                            e.grelha[li][ci] = VALOR_O;
                            li--;
                        }
                    break;
                case 2:
                    li--;
                    ci++;
                    if (e.peca == VALOR_X) {
                        while (e.grelha[li][ci] != VALOR_X) {
                            e.grelha[li][ci] = VALOR_X;
                            li--;
                            ci++;
                        }
                    } else
                        while (e.grelha[li][ci] != VALOR_O) {
                            e.grelha[li][ci] = VALOR_O;
                            li--;
                            ci++;
                        }
                    break;
                case 3:
                    ci++;
                    if (e.peca == VALOR_X) {
                        while (e.grelha[li][ci] != VALOR_X) {
                            e.grelha[li][ci] = VALOR_X;
                            ci++;
                        }
                    } else
                        while (e.grelha[li][ci] != VALOR_O) {
                            e.grelha[li][ci] = VALOR_O;
                            ci++;
                        }
                    break;
                case 4:
                    li++;
                    ci++;
                    if (e.peca == VALOR_X) {
                        while (e.grelha[li][ci] != VALOR_X && li < 8) {
                            e.grelha[li][ci] = VALOR_X;
                            li++;
                            ci++;
                        }
                    } else
                        while (e.grelha[li][ci] != VALOR_O) {
                            e.grelha[li][ci] = VALOR_O;
                            li++;
                            ci++;
                        }
                    break;

                case 5:
                   li++;
                    if (e.peca == VALOR_X) {
                        while (e.grelha[li][ci] != VALOR_X) {
                            e.grelha[li][ci] = VALOR_X;
                            li++;
                        }
                    } else
                        while (e.grelha[li][ci] != VALOR_O) {
                            e.grelha[li][ci] = VALOR_O;
                            li++;
                        }
                    break;

                case 6:
                    li++;
                    ci--;
                    if (e.peca == VALOR_X) {
                        while (e.grelha[li][ci] != VALOR_X) {
                            e.grelha[li][ci] = VALOR_X;
                            li++;
                            ci--;
                        }
                    } else
                        while (e.grelha[li][ci] != VALOR_O) {
                            e.grelha[li][ci] = VALOR_O;
                            li++;
                            ci--;
                        }
                    break;

                case 7:
                    ci--;
                    if (e.peca == VALOR_X) {
                        while (e.grelha[li][ci] != VALOR_X) {
                            e.grelha[li][ci] = VALOR_X;
                            ci--;
                        }
                    } else
                        while (e.grelha[li][ci] != VALOR_O) {
                            e.grelha[li][ci] = VALOR_O;
                            ci--;
                        }
                    break;

                case 8:
                    li--;
                    ci--;
                    if (e.peca == VALOR_X) {
                        while (e.grelha[li][ci] != VALOR_X) {
                            e.grelha[li][ci] = VALOR_X;
                            li--;
                            ci--;
                        }
                    } else
                        while (e.grelha[li][ci] != VALOR_O) {
                            e.grelha[li][ci] = VALOR_O;
                            li--;
                            ci--;
                        }
                    break;
            }
        }
    }
    return e;
}
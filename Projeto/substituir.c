#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "estado.h"

int substituiAux (ESTADO e,int dir,int l,int c) {
    int li = l - 1;
    int ci = c - 1;
    switch (dir) {
        case 1:
            if (e.peca == VALOR_X) {
                while (li != 0) {
                    if (e.grelha[li - 1][ci] == VAZIA) return 0;
                    if (e.grelha[li - 1][ci] == VALOR_X) return 1;
                    if (e.grelha[li - 1][ci] == VALOR_O) li--;
                }
                return 0;
            } else {
                while (li != 0) {
                    if (e.grelha[li - 1][ci] == VAZIA) return 0;
                    if (e.grelha[li - 1][ci] == VALOR_O) return 1;
                    if (e.grelha[li - 1][ci] == VALOR_X) li--;
                }
                return 0;
            }
        case 2:
            if (e.peca == VALOR_X) {
                while (li != 0 && ci != 7) {
                    if (e.grelha[li - 1][ci+1] == VAZIA) return 0;
                    if (e.grelha[li - 1][ci+1] == VALOR_X) return 2;
                    if (e.grelha[li - 1][ci+1] == VALOR_O) {
                        li--;
                        ci++;
                    }
                }
                return 0;
            } else {
                while (li != 0 && ci != 7) {
                    if (e.grelha[li - 1][ci+1] == VAZIA) return 0;
                    if (e.grelha[li - 1][ci+1] == VALOR_O) return 2;
                    if (e.grelha[li - 1][ci+1] == VALOR_X) {
                        li--;
                        ci++;
                    }
                }
                return 0;
            }
        case 3:
            if (e.peca == VALOR_X) {
                while (ci != 7) {
                    if (e.grelha[li][ci+1] == VAZIA) return 0;
                    if (e.grelha[li][ci+1] == VALOR_X) return 3;
                    if (e.grelha[li][ci+1] == VALOR_O) ci++;
                }
                return 0;
            } else {
                while (ci != 7) {
                    if (e.grelha[li][ci+1] == VAZIA) return 0;
                    if (e.grelha[li][ci+1] == VALOR_O) return 3;
                    if (e.grelha[li][ci+1] == VALOR_X) ci++;
                }
                return 0;
            }
        case 4:
            li++;
            ci++;
            if (li == 8 || ci == 8) return 0;
            if (e.peca == VALOR_X) {
                while (li != 7 && ci != 7) {
                    if (e.grelha[li][ci] == VAZIA) return 0;
                    if (e.grelha[li][ci] == VALOR_X) return 4;
                    if (e.grelha[li][ci] == VALOR_O) {
                        li++;
                        ci++;
                    }
                }
                return 0;
            } else {
                while (li != 7 && ci != 7) {
                    if (e.grelha[li][ci] == VAZIA) return 0;
                    if (e.grelha[li][ci] == VALOR_O) return 4;
                    if (e.grelha[li][ci] == VALOR_X) {
                        li++;
                        ci++;
                    }
                }
                return 0;
            }
        case 5:
            li++;
            if (li == 8) return 0;
            if (e.peca == VALOR_X) {
                while (li != 8) {
                    if (e.grelha[li][ci] == VAZIA) return 0;
                    if (e.grelha[li][ci] == VALOR_X) return 5;
                    if (e.grelha[li][ci] == VALOR_O) li++;
                }
                return 0;
            } else {
                while (li != 8) {
                    if (e.grelha[li][ci] == VAZIA) return 0;
                    if (e.grelha[li][ci] == VALOR_O) return 5;
                    if (e.grelha[li][ci] == VALOR_X) li++;
                }
                return 0;
            }
        case 6:
            li++;
            ci--;
            if (li == 8 || ci == -1) return 0;
            if (e.peca == VALOR_X) {
                while (li != 7 && ci != 0) {
                    if (e.grelha[li][ci] == VAZIA) return 0;
                    if (e.grelha[li][ci] == VALOR_X) return 6;
                    if (e.grelha[li][ci] == VALOR_O) {
                        li++;
                        ci--;
                    }
                }
                return 0;
            } else {
                while (li != 7 && ci != 0) {
                    if (e.grelha[li][ci] == VAZIA) return 0;
                    if (e.grelha[li][ci] == VALOR_O) return 6;
                    if (e.grelha[li][ci] == VALOR_X) {
                        li++;
                        ci--;
                    }
                }
                return 0;
            }
        case 7:
            if (e.peca == VALOR_X) {
                while (ci != 0) {
                    if (e.grelha[li][ci-1] == VAZIA) return 0;
                    if (e.grelha[li][ci-1] == VALOR_X) return 7;
                    if (e.grelha[li][ci-1] == VALOR_O) ci--;
                }
                return 0;
            } else {
                while (ci != 0) {
                    if (e.grelha[li][ci-1] == VAZIA) return 0;
                    if (e.grelha[li][ci-1] == VALOR_O) return 7;
                    if (e.grelha[li][ci-1] == VALOR_X) ci--;
                }
                return 0;
            }
        case 8:
            if (e.peca == VALOR_X) {
                while (li != 0 && ci != 0) {
                    if (e.grelha[li - 1][ci-1] == VAZIA) return 0;
                    if (e.grelha[li - 1][ci-1] == VALOR_X) return 8;
                    if (e.grelha[li - 1][ci-1] == VALOR_O) {
                        li--;
                        ci--;
                    }
                }
                return 0;
            } else {
                while (li != 0 && ci != 0) {
                    if (e.grelha[li - 1][ci-1] == VAZIA) return 0;
                    if (e.grelha[li - 1][ci-1] == VALOR_O) return 8;
                    if (e.grelha[li - 1][ci-1] == VALOR_X) {
                        li--;
                        ci--;
                    }
                }
                return 0;
            }
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
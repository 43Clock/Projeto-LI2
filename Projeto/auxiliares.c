#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "estado.h"


void opcoes () {
    printf("\nN <peça> para começar um novo jogo.\n");
    printf("L <ficheiro> ler ficheiro de jogo.\n");
    printf("E <ficheiro> para escrever ficheiro de jogo\n");
    printf("J <L,C> para fazer a jogada.\n");
    printf("S para mostrar as jogadas posiveis.\n");
    printf("H sugestão de jogada.\n");
    printf("U para desfazer a ultima jogada feita.\n");
    printf("A <peça> <nivel> novo jogo contra 'bot'.\n");
    printf("Q para sair.\n\n");
}

/**
 * @brief Esta função serve apenas fazer com que o estado de jogo volte ao inicial.
 * @param e Estado atual de jogo.
 * @return Retorna um novo inicio de jogo com a configuração inicial de peças.
 */
ESTADO reset (ESTADO e){
    int i,j;
    for (i = 0;i<8;i++)
        for (j = 0;j<8;j++)
            e.grelha[i][j] = VAZIA;
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;
    return e;
}

/**
 * @brief Esta função conta o numero de pontos de um certo jogador.
 * @param e O estado atual de jogo.
 * @param n O jogador o qual vai se contar as peças.
 * @return Retorna o numero de peças do jogador n.
 */
int conta (ESTADO e,VALOR n) {
    int i,j,acc = 0;
    for (i = 0;i<8;i++)
        for (j = 0;j<8;j++) {
            if ((e.grelha[i][j] ) == n) acc++;
        }
    return acc;
}
/**
 * @brief Função que apenas coloca uma peça na grelha numa determinada coordenada.
 * @param e Estado atual de jogo.
 * @param s Array que contem a posição onde o jogador pretende jogar.
 * @return Estado altera depois de colocar a peça.
 */
ESTADO jogar (ESTADO e,char s[]) {
    int l,c;
    int i;
    putchar('\n');
    for (i = 0;s[i] == 'j' || s[i] == 'J' ||s[i] == ' ' ;i++);
    l = s[i]-48;
    i++;
    for (;s[i] == 'j' || s[i] == 'J' ||s[i] == ' ' ;i++);
    c = s[i]-48;
    if (l-1 >= 8 || c-1 >= 8 || e.grelha[l-1][c-1] != VAZIA){
        printf("Posição Invalida\n");
    }
    else {
        e.grelha[l-1][c-1] = e.peca;
    }
    return e;
}
/**
 * @brief Função que verifica se as coordenadas que o jogador colocou são validas para serem jogadas.
 * @param e Estado atual do jogo.
 * @param l Linha que o jogador escolheu.
 * @param c Coluna que o jogador escolheu.
 * @return Retorna 1 se for possivel jogar na posição (l,c). Retorna 0 caso contrario.
 */
int possivelJogar (ESTADO e,int l, int c) {
    int i,r = 0;
    int li = l-1;
    int ci = c-1;
    VALOR v;
    if (e.peca == VALOR_X) v = VALOR_O;
    else v = VALOR_X;
    for (i = 1;i<9 && r == 0;i++) {
        switch (i) {
            case 1:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li-1][ci] == v && substituiAux(e,i,l,c) == i)
                    r = 1;
                break;

            case 2:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li-1][ci+1] == v && substituiAux(e,i,l,c) == i)
                    r = 1;
                break;

            case 3:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li][ci+1] == v && substituiAux(e,i,l,c) == i)
                    r = 1;
                break;

            case 4:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li+1][ci+1] == v && substituiAux(e,i,l,c) == i)
                    r = 1;
                break;

            case 5:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li+1][ci] == v && substituiAux(e,i,l,c) == i)
                    r = 1;
            break;

            case 6:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li+1][ci-1] == v && substituiAux(e,i,l,c) == i)
                    r = 1;
            break;

            case 7:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li][ci-1] == v && substituiAux(e,i,l,c) == i)
                    r = 1;
                break;

            case 8:
                if (e.grelha[li][ci] == VAZIA && e.grelha[li-1][ci-1] == v && substituiAux(e,i,l,c) == i)
                    r = 1;
                break;
        }
    }
    return r;
}

/**
 * @brief Esta função imprime no escrã o estado atual do jogo com o caracter '.' nas posições onde o jogador pode jogar.
 * @param e Estado atual de jogo.
 */
void helpPlz (ESTADO e) {
    int i,j;
    if (e.peca == VAZIA) printf("Ainda não começou o jogo !!!!\n\n");
    else {
        putchar('\n');
        printf("  1 2 3 4 5 6 7 8\n");
        for (i = 0; i < 8; i++) {
            printf("%d ", i + 1);
            for (j = 0; j < 8; j++) {
                if (e.grelha[i][j] == VALOR_X) printf("X ");
                else if (e.grelha[i][j] == VALOR_O) printf("O ");
                else {
                    if (possivelJogar(e, i + 1, j + 1) == 0) printf("- ");
                    else printf(". ");
                }
            }
            putchar('\n');
        }
        putchar('\n');
    }
}

/**
 * @brief Esta função, com recurso às funções do bot, imprime no ecrã o estado do jogo com a melhor posição para o jogador jogar.
 * @param e Estado atual do jogo.
 * @param l Linha onde o jogador deve jogar.
 * @param c Coluna onde o jogador deve jogar.
 */
void helpPlz2 (ESTADO e,int l,int c) {
    int i,j, r = 0;
    putchar ('\n');
    printf("  1 2 3 4 5 6 7 8\n");
    for (i = 0;i<8;i++) {
        printf("%d ",i+1);
        for (j = 0; j < 8; j++) {
            if (e.grelha[i][j] == VALOR_X) printf("X ");
            else if (e.grelha[i][j] == VALOR_O) printf("O ");
            else {
                if (i == l-1 && j == c-1){
                    printf("? ");
                    r++;
                }
                else printf("- ");
            }
        }
        putchar('\n');
    }
    putchar('\n');
    printf("%d %d\n",l,c);
}

/**
 * @brief Esta função verifica para ambos os jogadores se tem alguma jogada possivel.
 * @param e Estado atual de jogo.
 * @return Retorna 0 se o jogo já acabou (ou seja nenhum consegue jogar). Retorna 1 caso contrario.
 */
int acabou (ESTADO e) { // 0 == não ha jogadas possiveis
    int r = 0;
    int i,j;
    e.peca = VALOR_X;
    for (i = 0;i<8 && r == 0;i++)
        for (j = 0;j<8 && r == 0;j++)
            if (possivelJogar(e, i + 1, j + 1)) {
                r++;
            }
    e.peca = VALOR_O;
    for (i = 0;i<8 && r == 0;i++)
        for (j = 0;j<8 && r == 0;j++)
            if (possivelJogar(e, i + 1, j + 1)) {
                r++;
            }
    return r;
}

/**
 * @brief Esta função verifica se o jogador que está atualmente a jogar tem alguma jogada valida disponivel.
 * @param e Estado atual de jogo.
 * @return Retorna 1 caso tenha alguma jogada. Retorna 0 caso contrario.
 */
int podeJogar (ESTADO e) {
    int r = 0;
    int i,j;
    for (i = 0;i<8 && r == 0;i++)
        for (j = 0;j<8 && r == 0;j++)
            if  (possivelJogar(e,i+1,j+1)) r = 1;
    return  r;
}

/**
 * @Esta Função é usada para apagar/começar uma nova lista ligada. Caso a lista não seja vazia vai fazer free antes de a iniciar de novo.
 * @param s Apontador para a lista ligada atual.
 */
void initStack (STACK *s) {
    STACK aux = NULL;
    if (*s != NULL) {
        while (*s != NULL) {
            aux = *s;
            *s = (*s) -> ant;
            free(aux);
        }
    }
    else *s = NULL;
}
/**
 * @brief Função que verifica se a lista ligada é vazia ou se tem apenas um elemento.
 * @param s Apontador para a lista ligada atual.
 * @return Retorna 1 caso não esteja vazia. Retorna 0 caso contrario.
 */
int isEmpty (STACK *s) {
    return (*s == NULL || (*s) -> ant == NULL);
}

/**
 * @brief Esta função faz um novo malloc do estado atual do jogo e mete-o a apontar para a lista ligada.
 * @param e Estado que vai ser colocado na lista ligada.
 * @param s Apontador para a lista ligada atual.
 */
void push (ESTADO e,STACK *s) {
    STACK novo = (STACK) malloc(sizeof(struct stack));
    novo -> e = e;
    novo -> ant = *s;
    *s = novo;
}

/**
 * @brief Esta função server para fazer o undo e vẽ qual é o estado que se encontrava antes na lista ligada.
 * @param e Estado atual do jogo.
 * @param s Apontador para a lista ligada atual.
 * @return Retorna o estado que estava na jogada anterior.
 */
ESTADO pop (ESTADO e,STACK *s) {
    STACK aux = *s;
    aux = aux -> ant;
    e = aux -> e;
    *s = aux;
    printf("\n");
    printa(e);
    printf("\n");
    return e;
}


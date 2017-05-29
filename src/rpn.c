/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * rpn.c - Define a função responsável para lidar com uma   *
 * expressão em Notação Polonesa Reversa.                   *
 * ======================================================== */

#include <stdlib.h>
#include "rpn.h"

/*
* Resolve a operação em RPN.
*
* Parâmetros:
*   * s  - pilha contendo os operandos
*   * op - operação para execução ( + ou * )
*
* Retorna:
*   * int - resultado da operação
*/
int evaluateRPN( stack s, char op ) {

    int res = 0;

    // determina a operação e executa
    switch ( op ) {
        case SUM_OP:
            res = pop(s) + pop(s);
            break;

        case MUL_OP:
            res = pop(s) * pop(s);
    }

    return res;
}

/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * rpn.c - Define o cabeçalho da função responsável para    *
 * lidar com uma expressão em Notação Polonesa Reversa.     *
 * ======================================================== */

#ifndef _RPN_H_
#define _RPN_H_

#include "stack.h"

/*
 * Define os char's + e * como SUM_OP e MUL_OP respectivamente.
 */
#define SUM_OP '+'
#define MUL_OP '*'

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
int evaluateRPN( stack s, char op );

#endif // _RPN_H_

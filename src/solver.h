/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * solver.c - Define o cabeçalho de funções relacionadas    *
 * ao problema proposto. Lida com a expressão fornecida     *
 * para gerar as combinações que satisfazem o resultado     *
 * ======================================================== */

#ifndef _SOLVER_H_
#define _SOLVER_H_

#include "vector.h"
#include "stack.h"
#include "rpn.h"

/* Dado que neste trabalho apenas números inteiros são inseridos,
 * defini o ponto de interrogação como -1.
 */
#define QUESTION_MARK -1

/*
* Pre-processamento para inciar o teste das combinações.
*
* Parâmetros:
*   * v              - vetor que contém a expressão em RPN
*   * result         - resultado fornecido da expressão RPN
*   * question_marks - quantidade de operações incógnitas
*/
void solve( vector v, int result, int question_marks );

#endif // _SOLVER_H_

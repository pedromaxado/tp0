/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * solver.c - Define funções relacionadas ao problema       *
 * proposto. Lida com a expressão fornecida para gerar      *
 * as combinações que satisfazem o resultado.               *
 * ======================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"
#include "solver.h"

/*
* Teste as combinações possíveis recursivamente.
*
* Parâmetros:
*   * v            - vetor de operandos e operadores
*   * pos          - posição atual no vetor de operandos e operadores
*   * op           - operação a ser realizada no topo da pilha
*   * s            - pilha contendo os operandos
*   * result       - resultado da expressão fornecido
*   * combinations - vetor de char que armazena a ordem dos operadores para posterior impressão
*   * comb_pos     - posição atual no vetor de char
*
*/
void recursiveSolver( vector v, int pos, char op, stack s, int result, char* combinations, int comb_pos ) {

    int temp;

    // trata o sinal recebido
    if ( op == SUM_OP ) {
        temp = evaluateRPN( s, SUM_OP );

        /* caso o resultado seja maior que o esperado, retorna
           se não, insere na pilha e adiciona a operação no vetor
           de combinações */
        if ( temp > result ) {
            return;
        }
        else {
            push( s, temp );
            combinations[comb_pos] = '+';
            comb_pos++;
        }
    }
    else if ( op == MUL_OP ) {
        temp = evaluateRPN( s, MUL_OP );

        /* mesma coisa de cima */
        if ( temp > result ) {
            return;
        }
        else {
            push( s, temp );
            combinations[comb_pos] = '*';
            comb_pos++;
        }
    }

    if ( pos == vectorSize(v) ) {

        /* se chegou ao final da expressão RPN e o resultado
           esperado foi atingido, imprime os operadores */
        if ( top(s) == result )
            printf("%s\n", combinations);

        return;
    }

    int i = pos;

    /* se não chegou no final da expressão, enquanto houver
       operandos, vai colocando eles na pilha. */
    while ( get(v, i) != QUESTION_MARK ) {
        push( s, get(v, i) );
        i++;
    }

    /* pra cada um dos operadores, uma chamada recursiva é feita
       para testá-los */

    stack s1 = new_stack();
    copy(s, s1);

    /* chamada para a operação de soma */
    recursiveSolver( v, i+1, SUM_OP, s1, result, combinations, comb_pos );

    delete_stack(s1);

    stack s2 = new_stack();
    copy(s, s2);

    /* chamada para a operação de multiplicação */
    recursiveSolver( v, i+1, MUL_OP, s2, result, combinations, comb_pos );

    delete_stack(s2);

}

/*
* Pre-processamento para inciar o teste das combinações.
*
* Parâmetros:
*   * v              - vetor que contém a expressão em RPN
*   * result         - resultado fornecido da expressão RPN
*   * question_marks - quantidade de operações incógnitas
*/
void solve( vector v, int result, int question_marks ) {

    int i;
    stack s = new_stack();

    /* vetor de char para armazenar a ordem dos operandos que satisfazem o resultado */
    char* combinations = ( char* ) malloc( (question_marks + 1) * sizeof( char ) );

    for ( i = 0; i < question_marks; i++ )
        combinations[i] = ' ';

    combinations[i] = '\0';

    /* Chamada da função core do trabalho prático responsável por descobrir as combinações. */
    recursiveSolver( v, 0, ' ', s, result, combinations, 0 );

    delete_stack( s );
    free(combinations);
}

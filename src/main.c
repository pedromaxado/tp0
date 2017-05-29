/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * main.c - Arquivo principal responsável por tratar a      *
 * as entradas e implementar a função que gera as com-      *
 * binações.
 * ======================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solver.h"
#include "vector.h"

#define MAX 256 /* Define o tamanho máximo para o vetor que vai receber a entrada. */

/*
* Divide a entrada para processar cada elemento.
* Parâmetro:
*   * str  - string que contém a expressão lida na entrada
*   * expr - vetor de inteiros que armazenará os operandos e posição dos operadores
*
* Retorna:
*   * int - Inteiro contendo a quantidade de "?" na entrada.
*/
int split( char* str, vector expr ) {

    int question_marks = 0;
    char* token;

    token = strtok( str, " " );

    // enquanto houver substrings, trato fazendo as devidas decisões
    while ( token != NULL ) {
        if ( atoi( token ) ) {
            add( expr, atoi(token) );
        }
        else {
            add( expr, QUESTION_MARK );
            question_marks++;
        }

        token = strtok( NULL, " " );
    }

    return question_marks;
}

int main() {

    vector expression = new_vector();
    char buffer[MAX];
    int result = 0;

    if ( fgets( buffer, MAX, stdin ) ) {
        if ( scanf("%d", &result) > 0 ) {

            int question_marks;

            /* tratamento da entrada e obtenção da quantidade de "?" */
            question_marks = split( buffer, expression );

            /* função principal que resolve o problema */
            solve( expression, result, question_marks );
        }
    }

    delete_vector( expression );

    return 0;
}

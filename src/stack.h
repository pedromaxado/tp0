/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * stack.c - Define a estrutura de dados e cabeçalho de     *
 * funções relacionadas a manipulação de um TAD pilha       *
 * ======================================================== */

#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

/* definição do tipo stack */
typedef struct stack_t* stack;

/*
* Cria uma pilha vazia.
*
* Retorna:
*   * stack - Nova pilha criada
*/
stack new_stack();

/*
* Libera a memória utilizada pela pilha.
*
* Parâmetro:
*   * s - pilha a ser apagada
*/
void delete_stack( stack s );

/*
* Insere um elemento na pilha.
*
* Parâmtros:
*   * s - pilha
*   * k - elemento a ser inserido
*/
void push( stack s, int k );

/*
* Remove o elemento no topo da pilha.
*
* Parâmetro:
*   * s - pilha que terá seu elemento "popado"
*
* Retorna:
*   * int - Elemento removido
*/
int pop( stack s );

/*
* Retorna o elemento no topo da pilha.
*
* Parâmetros:
*   * s - pilha
*
* Retorna:
*   * int - Elemento do topo da pilha
*/
int top( stack s );

/*
* Copia os elementos da pilha p para s.
*
* Parâmetros:
*   * p - pilha origem
*   * s - pilha destino
*/
void copy( stack p, stack s );

/*
* Retorna o tamanho da pilha, aka, quantidade de
* elementos nela contida.
*
* Parâmetro:
*   * s - pilha
*
* Retorna:
*   * int - Tamanho da pilha
*/
int stackSize( stack s );

/*
* Retorna se uma pilha está vazia ou não.
*
* Parâmetro:
*   * s - pilha
*
* Retorna:
*   * bool - true se vazia, false se não
*/
bool isStackEmpty( stack s );

#endif // _STACK_H_

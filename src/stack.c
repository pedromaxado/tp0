/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * stack.c - Define funções para manipulação de uma TAD     *
 * pilha implementada com array de inteiros.                *
 * ======================================================== */

#include <stdlib.h>
#include <limits.h>
#include "stack.h"

#define INIT_CAPACITY 16

struct stack_t {
    int* arr;
    int capacity;
    int size;
};

/*
* Aumenta o tamanho do array que contém a pilha.
*
* Parâmetros:
*   * s - pilha
*   * m - tamanho desejado da pilha
*/
void reserveStack( stack s, int m ) {

    if ( m > s->capacity ) {
        s->capacity = m;
        int* aux = malloc( sizeof( int ) * s->capacity );

        for ( int i = 0; i < s->size; i++ )
            aux[i] = s->arr[i];

        free(s->arr);
        s->arr = aux;
    }
}

/*
* Cria uma pilha vazia.
*
* Retorna:
*   * stack - Nova pilha criada
*/
stack new_stack() {
    stack s = malloc( sizeof( struct stack_t ) );

    s->capacity = INIT_CAPACITY;
    s->size     = 0;
    s->arr      = malloc( INIT_CAPACITY * sizeof( int ) );

    return s;
}

/*
* Libera a memória utilizada pela pilha.
*
* Parâmetro:
*   * s - pilha a ser apagada
*/
void delete_stack( stack s ) {
    free( s->arr );
    free( s );
}

/*
* Insere um elemento na pilha.
*
* Parâmtros:
*   * s - pilha
*   * k - elemento a ser inserido
*/
void push( stack s, int k ) {
    if ( s->size == s->capacity )
        reserveStack( s, 2 * s->capacity );

    s->arr[s->size] = k;
    s->size++;
}

/*
* Remove o elemento no topo da pilha.
*
* Parâmetro:
*   * s - pilha que terá seu elemento "popado"
*
* Retorna:
*   * int - Elemento removido
*/
int pop( stack s ) {

    int k = top(s);

    if ( s->size > 0 )
       s->size--;

    return k;
}

/*
* Retorna o elemento no topo da pilha.
*
* Parâmetros:
*   * s - pilha
*
* Retorna:
*   * int - Elemento do topo da pilha
*/
int top( stack s ) {
    int k = INT_MAX;

    if ( s->size > 0 )
        k = s->arr[s->size-1];

    return k;
}

/*
* Copia os elementos da pilha p para s.
*
* Parâmetros:
*   * p - pilha origem
*   * s - pilha destino
*/
void copy(stack p, stack s) {

    reserveStack( s, p->capacity );

    s->size = p->size;

    for ( int i = 0; i < p->size; i++ )
        s->arr[i] = p->arr[i];

}

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
int stackSize( stack s ) {
    return s->size;
}

/*
* Retorna se uma pilha está vazia ou não.
*
* Parâmetro:
*   * s - pilha
*
* Retorna:
*   * bool - true se vazia, false se não
*/
bool isStackEmpty( stack s ) {
    return s->size == 0;
}

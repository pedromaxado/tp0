/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * vector.c - Define funções para manipulação de uma TAD    *
 * vetor implementada com array de inteiros.                *
 * ======================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "vector.h"

#define INIT_CAPACITY 16

/*
* Struct da TAD encapsulada.
*
* Membros:
*   * capacity - inteiro que armazena o capacidade atual do vetor
*   * size     - inteiro que armazena o tamanho atual do vetor
*   * array    - Vetor em si que armazena os elementos do tipo int
*/
struct vector_t {

	int capacity;
	int size;

	int* array;
};

/*
* Aumenta o tamanho do array que contém os elementos.
*
* Parâmetros:
*   * v - vetor
*   * m - tamanho desejado do vetor
*/
void reserveVector( vector v, int m ) {

	if ( m > v->capacity ) {

		v->capacity = m;

		int* aux = malloc( sizeof( int ) * v->capacity );

		for ( int i = 0; i < v->size; i++ )
			aux[i] = v->array[i];

		free( v->array );

		v->array = aux;
	}
}

/*
* Cria um vetor vazio.
*
* Retorna:
*   * vector - Novo vetor criado
*/
vector new_vector() {

	vector v = ( vector ) malloc ( sizeof( struct vector_t ) );

	v->size = 0;
	v->capacity = INIT_CAPACITY;

	v->array = ( int* ) malloc( INIT_CAPACITY * sizeof( int ) );

	return v;
}

/*
* Libera a memória utilizada pelo vetor.
*
* Parâmetro:
*   * v - vetor a ser apagado
*/
void delete_vector( vector v ) {
	free(v->array);
	free(v);
}

/*
* Insere um elemento no vetor.
*
* Parâmtros:
*   * v - vetor
*   * k - elemento a ser inserido
*/
void add( vector v, int k ) {

	if ( v->size == v->capacity )
		reserveVector( v, 2*v->capacity );

	v->array[v->size] = k;
	v->size++;
}

/*
* Retorna o elemento do vetor em uma dada posição.
*
* Parâmtros:
*   * v - vetor
*   * pos - posição do elemento
*/
int get ( vector v, int pos ) {

	int k = INT_MAX;

	if ( pos < v->size )
		k = v->array[pos];

	return k;
}

/*
* Retorna o tamanho do vetor, aka, quantidade de
* elementos nele contido.
*
* Parâmetro:
*   * v - vetor
*
* Retorna:
*   * int - Tamanho do vetor
*/
int vectorSize( vector v ) {
	return v->size;
}

/*
* Retorna a capacidade atual do vetor.
*
* Parâmetro:
*   * v - vetor
*
* Retorna:
*   * int - Capacidade do vetor
*/
int capacity( vector v ) {
    return v->capacity;
}

/*
* Retorna se um vetor está vazio ou não.
*
* Parâmetro:
*   * v - vetor
*
* Retorna:
*   * bool - true se vazio, false se não
*/
bool isVectorEmpty( vector v ) {
	return v->size == 0;
}

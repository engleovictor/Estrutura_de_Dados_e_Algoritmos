#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdlib.h>
#include <stdio.h>

void inserir(int *heap, int *size, int elem);
int remover(int *heap, int *size);
int acessar(int *heap);

void subir(int *heap, int last);
void descer(int *heap, int size, int pos);


void colocar_em_ordem_crescente(int *heap, int size);

// Func de Debug
void mostrar_heap(int *heap, int size);
#endif // __HEAP_H__
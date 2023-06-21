#ifndef __ARVOREB_H__
#define __ARVOREB_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct arvoreb {
    int size;
    int qnt;
    int *vals;
    struct arvoreb **subtrees;
} ArvoreB;

ArvoreB *newSubtree(int size);
int buscaBinaria(int *vals, int size, int chave);
int inserirChave(ArvoreB *T, int chave);

#endif // __ARVOREB_H__
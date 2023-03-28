#include <stdlib.h>
#include <stdio.h>
#include "arvore_binaria.h"

ArvoreBinaria *montarArPreSim(int *pre, int *sim, int tam) {
    if(tam == 1) {
        ArvoreBinaria *new = (ArvoreBinaria *) malloc(sizeof(ArvoreBinaria));
        new->chave = pre[0];
        new->dir   = NULL;
        new->esq   = NULL;
        return new;
    }
    int i = 0;
    int val = pre[0];
    while(pre[0] != sim[i]) i++;
    ArvoreBinaria *new = (ArvoreBinaria *) malloc(sizeof(ArvoreBinaria));
    new->chave = val;
    new->esq   = montarArPreSim(&(pre[1]),&(sim[0]),i);
    new->dir   = montarArPreSim(&(pre[i+1]),&(sim[i+1]),tam-(i + 1));
    return new;
}

void printarPreOrdem(ArvoreBinaria *head) {
    if(head) {
        printf("%d, ", head->chave);
        printarPreOrdem(head->esq);
        printarPreOrdem(head->dir);
    }
}

void printarPosOrdem(ArvoreBinaria *head) {
    if(head) {
        printarPosOrdem(head->esq);
        printarPosOrdem(head->dir);
        printf("%d, ", head->chave);
    }
}

void printarSimetric(ArvoreBinaria *head) {
    if(head) {
        printarSimetric(head->esq);
        printf("%d, ", head->chave);
        printarSimetric(head->dir);
    }
}

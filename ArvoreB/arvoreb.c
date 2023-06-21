#include "arvoreb.h"

ArvoreB *newSubtree(int size) {
    if(size <= 0) return NULL;
    ArvoreB *new = (ArvoreB *) malloc(sizeof(ArvoreB));
    new->vals = (int *) malloc(sizeof(int)*size);
    new->subtrees = (ArvoreB **) malloc(sizeof(ArvoreB *)*(size+1));
    for(int i=0;i<size+1;i++) new->subtrees[i] = NULL;
    new->qnt = 0;
    return new;
}

int buscaBinaria(int *vals, int size,int chave) {
    // Função que retorna ultima chave visitada;
    if(size == 0) return -1; // Página vazia;
    if(size == 1) return 0;
    int p = size/2;
    if(vals[p] == chave) return p;
    else if(vals[p] < chave) return buscaBinaria(&(vals[p+1]),size-(p+1),chave) + p + 1;
    else return buscaBinaria(vals,p,chave);
}

int inserirChave(ArvoreB *T, int chave) {

}

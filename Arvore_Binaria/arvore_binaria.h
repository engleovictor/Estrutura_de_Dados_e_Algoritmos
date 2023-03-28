#ifndef _ARVORE_BINARIA_H_
#define _ARVORE_BINARIA_H_

typedef struct arvore_binaria{
    int chave;
    struct arvore_binaria *esq, *dir;
} ArvoreBinaria;

ArvoreBinaria *montarArPreSim(int *pre, int *sim, int tam);
void printarPreOrdem(ArvoreBinaria *head);
void printarPosOrdem(ArvoreBinaria *head);
void printarSimetric(ArvoreBinaria *head);


#endif /* _ARVORE_BINARIA_H_ */
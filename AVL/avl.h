#ifndef _AVL_H_
#define _AVL_H_

#include "../Arvore_Binaria_de_Busca/arvore_binaria_de_busca.h"

void rotEsq(ArvoreBinaria **T, int chave);
void rotDir(ArvoreBinaria **T, int chave);
void doubleRotEsq(ArvoreBinaria **T, int chave);
void doubleRotDir(ArvoreBinaria **T, int chave);
int maxint(int a, int b);
int alturaArvore(ArvoreBinaria *T);
int desnivel(ArvoreBinaria *T);
void otimizaArvore(ArvoreBinaria **T);

typedef struct avl {
    int chave;
    struct avl *esq, *dir;
    int bal;
} ArvoreAVL;

int inserirAVL(ArvoreAVL **T, int chave);
void printarPreOrdemAVL(ArvoreAVL *head);
void printarPosOrdemAVL(ArvoreAVL *head);
void printarSimetricAVL(ArvoreAVL *head);
void rotEsqAVL(ArvoreAVL **T, int chave);
void rotDirAVL(ArvoreAVL **T, int chave);
void doubleRotEsqAVL(ArvoreAVL **T, int chave);
void doubleRotDirAVL(ArvoreAVL **T, int chave);
ArvoreAVL *buscaArvoreAVL(ArvoreAVL *princ, ArvoreAVL **pai, int chave);

#endif // _AVL_H_
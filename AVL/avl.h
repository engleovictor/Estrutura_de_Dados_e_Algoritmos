#ifndef _AVL_H_
#define _AVL_H_

typedef struct avl {
    int chave;
    struct avl *esq, *dir;
    int bal;
} ArvoreAVL;

ArvoreAVL *newSubTree(int chave);
int inserirChave(ArvoreAVL **T, int chave);
int buscarChave(ArvoreAVL *T, int chave);
int removerChave(ArvoreAVL **T, ArvoreAVL **pai, int chave);
void preordem(ArvoreAVL *T);
int rotEsq(ArvoreAVL **T);
int rotDir(ArvoreAVL **T);
int doubleRotEsq(ArvoreAVL **T);
int doubleRotDir(ArvoreAVL **T);

#endif  //_AVL_H_;
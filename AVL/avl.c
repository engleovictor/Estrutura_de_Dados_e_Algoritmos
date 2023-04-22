#include "avl.h"
#include <stdlib.h>
#include <stdio.h>
/*
// void rotEsq(ArvoreBinaria **T, int chave) {
//     ArvoreBinaria *pai    = NULL;
//     ArvoreBinaria *aux    = buscaArvoreBinariadeBusca(*T,&pai,chave);
//     if(aux->dir == NULL) return ; // Não tem ninguem a direita, não tem como rodar!
//     ArvoreBinaria *newaux = aux->dir;
//     if(pai != NULL) {
//         if(pai->dir != NULL && aux->chave == pai->dir->chave) {
//             pai->dir = aux->dir;
//         } else if(pai->esq != NULL && aux->chave == pai->esq->chave) {
//             pai->esq = aux->dir;
//         } else {
//             // Não achou, portanto não faz nada!
//             return ;
//         }
//     } else (*T) = aux->dir;
//     ArvoreBinaria *p;
//     p = newaux->esq;
//     newaux->esq = aux;
//     aux->dir = p;
//     return ; 
// }

// void rotDir(ArvoreBinaria **T, int chave) {
//     ArvoreBinaria *pai    = NULL;
//     ArvoreBinaria *aux    = buscaArvoreBinariadeBusca(*T,&pai,chave);
//     if(aux->esq == NULL) return ; // Não tem ninguem a esquerda, não tem como rodar!
//     ArvoreBinaria *newaux = aux->esq;
//     if(pai != NULL) {
//         if(pai->dir != NULL && aux->chave == pai->dir->chave) {
//             pai->dir = aux->esq;
//         } else if(pai->esq != NULL && aux->chave == pai->esq->chave) {
//             pai->esq = aux->esq;
//         } else {
//             // Não achou, portanto não faz nada!
//             return ;
//         }
//     } else (*T) = aux->esq;
//     ArvoreBinaria *p;
//     p = newaux->dir;
//     newaux->dir = aux;
//     aux->esq = p;
//     return ; 
// }

// void doubleRotEsq(ArvoreBinaria **T, int chave) {
//     ArvoreBinaria *pai = NULL;
//     ArvoreBinaria *aux = buscaArvoreBinariadeBusca(*T,&pai,chave);
//     if(aux->dir == NULL || aux->dir->esq == NULL) return;
//     rotDir(&aux,aux->dir->chave);
//     if(pai == NULL) rotEsq(T,chave);
//     else rotEsq(&pai, chave);
//     return ;   
// }

// void doubleRotDir(ArvoreBinaria **T, int chave) {
//     ArvoreBinaria *pai = NULL;
//     ArvoreBinaria *aux = buscaArvoreBinariadeBusca(*T,&pai,chave);
//     if(aux->esq == NULL || aux->esq->dir == NULL) return;
//     rotEsq(&aux,aux->esq->chave);
//     if(pai == NULL) rotDir(T,chave);
//     else rotDir(&pai, chave);
//     return ;   
// }

// int maxint(int a, int b) {
//     if(a > b) return a;
//     else return b;
// }

// int alturaArvore(ArvoreBinaria *T) {
//     if(T == NULL) return 0; // Caso passar arvore Null, além disso, usado na func otimizaArvore() pro caso de T->dir ou esq NULL;
//     if(T->esq == NULL && T->dir == NULL) return 1;
//     else if(T->esq == NULL) return alturaArvore(T->dir) + 1;
//     else if(T->dir == NULL) return alturaArvore(T->esq) + 1;
//     else return maxint(alturaArvore(T->dir),alturaArvore(T->esq)) + 1; 
// }

// int desnivel(ArvoreBinaria *T) {
//     return alturaArvore(T->dir) - alturaArvore(T->esq);
// }

// void otimizaArvore(ArvoreBinaria **T) {
    
//     if((*T)->dir == NULL && (*T)->esq == NULL) return ;
    
//     if((*T)->esq != NULL) otimizaArvore(&((*T)->esq));
//     if((*T)->dir != NULL) otimizaArvore(&((*T)->dir));

//     int val = desnivel(*T);
//     if(val > 1) {
//         val = desnivel((*T)->dir);
//         if(val < 0) doubleRotEsq(T,(*T)->chave);
//         else rotEsq(T,(*T)->chave);
//         otimizaArvore(&((*T)->esq)); // Tem que refazer toda vez que rotacionar;
//     } else if(val < -1) {
//         val = desnivel((*T)->esq);
//         if(val > 0) doubleRotDir(T,(*T)->chave);
//         else rotDir(T,(*T)->chave);
//         otimizaArvore(&((*T)->dir)); // Tem que refazer toda vez que rotacionar;
//     } else return ;
// }
*/

int inserirAVL(ArvoreAVL **T, int chave) {
    
    int cresceu_rot = 0;
    
    if((*T) == NULL) { // ArvoreAVL vazia; 
        ArvoreAVL *new = (ArvoreAVL *) malloc(sizeof(ArvoreAVL));
        new->chave     = chave;
        new->bal       = 0;
        new->dir       = NULL;
        new->esq       = NULL;
        *T             = new;
        return 1;

    } else {
        if((*T)->chave > chave) {
            cresceu_rot = inserirAVL(&((*T)->esq),chave);
            if(cresceu_rot == 1) ((*T)->bal)--;
            else if(cresceu_rot == 2) ((*T)->bal)++;
        } else if((*T)->chave < chave) {
            cresceu_rot = inserirAVL(&((*T)->dir),chave);
            if(cresceu_rot == 1) ((*T)->bal)++;
            else if(cresceu_rot == 3) ((*T)->bal)--;
        } else return 0; // Então as chaves são iguais;

        if((*T)->bal == 2) {
            ArvoreAVL *aux = (*T)->dir;
            if(aux->bal < 0) doubleRotEsqAVL(T, (*T)->chave);
            else rotEsqAVL(T, (*T)->chave);
            (*T)->bal = 0;
            aux->bal = 0;
            cresceu_rot = 2;
        } else if((*T)->bal == -2) {
            ArvoreAVL *aux = (*T)->esq;
            if(aux->bal > 0) doubleRotDirAVL(T, (*T)->chave);
            else rotDirAVL(T, (*T)->chave);
            (*T)->bal = 0;
            aux->bal = 0;
            cresceu_rot = 3;
        } 
        
    } return cresceu_rot;
}

void rotEsqAVL(ArvoreAVL **T, int chave) {
    ArvoreAVL *pai    = NULL;
    ArvoreAVL *aux    = buscaArvoreAVL(*T,&pai,chave);
    if(aux->dir == NULL) return ; // Não tem ninguem a direita, não tem como rodar!
    ArvoreAVL *newaux = aux->dir;
    if(pai != NULL) {
        if(pai->dir != NULL && aux->chave == pai->dir->chave) {
            pai->dir = aux->dir;
        } else if(pai->esq != NULL && aux->chave == pai->esq->chave) {
            pai->esq = aux->dir;
        } else {
            // Não achou, portanto não faz nada!
            return ;
        }
    } else (*T) = aux->dir;
    ArvoreAVL *p;
    p = newaux->esq;
    newaux->esq = aux;
    aux->dir = p;
    return ; 
}

void rotDirAVL(ArvoreAVL **T, int chave) {
    ArvoreAVL *pai    = NULL;
    ArvoreAVL *aux    = buscaArvoreAVL(*T,&pai,chave);
    if(aux->esq == NULL) return ; // Não tem ninguem a esquerda, não tem como rodar!
    ArvoreAVL *newaux = aux->esq;
    if(pai != NULL) {
        if(pai->dir != NULL && aux->chave == pai->dir->chave) {
            pai->dir = aux->esq;
        } else if(pai->esq != NULL && aux->chave == pai->esq->chave) {
            pai->esq = aux->esq;
        } else {
            // Não achou, portanto não faz nada!
            return ;
        }
    } else (*T) = aux->esq;
    ArvoreAVL *p;
    p = newaux->dir;
    newaux->dir = aux;
    aux->esq = p;
    return ; 
}

void doubleRotEsqAVL(ArvoreAVL **T, int chave) {
    ArvoreAVL *pai = NULL;
    ArvoreAVL *aux = buscaArvoreAVL(*T,&pai,chave);
    if(aux->dir == NULL || aux->dir->esq == NULL) return;
    rotDirAVL(&aux,aux->dir->chave);
    if(pai == NULL) rotEsqAVL(T,chave);
    else rotEsqAVL(&pai, chave);
    return ;   
}

void doubleRotDirAVL(ArvoreAVL **T, int chave) {
    ArvoreAVL *pai = NULL;
    ArvoreAVL *aux = buscaArvoreAVL(*T,&pai,chave);
    if(aux->esq == NULL || aux->esq->dir == NULL) return;
    rotEsqAVL(&aux,aux->esq->chave);
    if(pai == NULL) rotDirAVL(T,chave);
    else rotDirAVL(&pai, chave);
    return ;   
}

ArvoreAVL *buscaArvoreAVL(ArvoreAVL *princ, ArvoreAVL **pai, int chave) { 
    if(princ == NULL) return NULL;
    if(princ->chave == chave) {
        return princ;
    }
    else if(princ->chave > chave) {
        if(princ->esq != NULL) { 
            *pai = princ;
            return buscaArvoreAVL(princ->esq,pai,chave);
        } else return princ;
    } else {
        if(princ->dir != NULL) {
            *pai = princ;
            return buscaArvoreAVL(princ->dir,pai,chave);
        } else return princ;
    }
}

void printarPreOrdemAVL(ArvoreAVL *head) {
    if(head != NULL) {
        printf("%d, ", head->chave);
        printarPreOrdemAVL(head->esq);
        printarPreOrdemAVL(head->dir);
    }
}

void printarPosOrdemAVL(ArvoreAVL *head) {
    if(head != NULL) {
        printarPosOrdemAVL(head->esq);
        printarPosOrdemAVL(head->dir);
        printf("%d, ", head->chave);
    }
}

void printarSimetricAVL(ArvoreAVL *head) {
    if(head != NULL) {
        printarSimetricAVL(head->esq);
        printf("%d, ", head->chave);;
        printarSimetricAVL(head->dir);
    }
}

int removerAVL(ArvoreAVL **T, ArvoreAVL **pai, int chave) {
    int diminui = 0;
    
    ArvoreAVL *t = *T;

    if(t == NULL) return 0;
    
    if(chave == t->chave) {
        if(t->esq == NULL && t->dir == NULL) {
            if(*pai != NULL && (*pai)->chave >= chave) (*pai)->esq = NULL; // <= & >= por ocasiao de remover 3 caso trocando com o proprio pai.    
            else if(*pai != NULL && (*pai)->chave <= chave) (*pai)->dir = NULL; 
            else t = NULL;
            free(t);
            return 1;
        } else if(t->esq == NULL) {
            if(*pai != NULL) {
                if((*pai)->chave > chave) (*pai)->esq = t->dir;
                if((*pai)->chave < chave) (*pai)->dir = t->dir;
            } else *T = t->dir;
            free(t);
            return 1;
        } else if(t->dir == NULL) {
            if(*pai != NULL) {
                if((*pai)->chave > chave) (*pai)->esq = t->esq;
                if((*pai)->chave < chave) (*pai)->dir = t->esq;
            } else *T = t->esq;
            free(t);
            return 1;
        } else { //caso não folha e não só um filho apenas;
            ArvoreAVL *paier  = *T;
            ArvoreAVL *aux    = buscaArvoreAVL((*T)->esq,&paier,chave);
            (*T)->chave = aux->chave;
            return removerAVL(&aux,&paier,aux->chave);
        }
        
    } else if(chave > t->chave) {
        diminui = removerAVL(&((*T)->dir),T,chave);
        if(diminui == 1) t->bal--;
        if(diminui == 3) t->bal++;
    } else { // chave ta na esq;
        diminui = removerAVL(&((*T)->esq),T,chave);
        if(diminui == 1) t->bal++;
        if(diminui == 2) t->bal--;
    }
    if((*T)->bal == 2 && diminui != 0) {
            ArvoreAVL *aux = (*T)->dir;
            (*T)->bal = 0;
            if(aux->bal < 0) doubleRotEsqAVL(T, (*T)->chave);
            else rotEsqAVL(T, (*T)->chave);
            aux->bal = 0;
            diminui = 2;
    } else if((*T)->bal == -2 && 0 != diminui) {
            ArvoreAVL *aux = (*T)->esq;
            (*T)->bal = 0;
            if(aux->bal > 0) doubleRotDirAVL(T, (*T)->chave);
            else rotDirAVL(T, (*T)->chave);
            aux->bal = 0;
            diminui = 3;

    } return diminui;
}
#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

ArvoreAVL *newSubTree(int chave) {
    ArvoreAVL *new = (ArvoreAVL *) malloc(sizeof(ArvoreAVL));
    new->chave = chave;
    new->dir = NULL;
    new->esq = NULL;
    new->bal = 0;
    return new;
}

int inserirChave(ArvoreAVL **T, int chave) {
    if(*T == NULL) {
        *T = newSubTree(chave);
        return 1;
    }

    ArvoreAVL *t = *T;
    int verif = 0;

    if(t->chave == chave) return 0;
    else if(t->chave > chave) {
        verif = inserirChave(&(t->esq), chave);
        if(verif == 1) {
            if(t->bal > 0) {
                (t->bal)--;
                return 0;
            } else {
                (t->bal)--;
            }
        }
    }
    else {
        verif = inserirChave(&(t->dir), chave);
        if(verif == 1) {
            if(t->bal < 0) {
                (t->bal)++;
                return 0;
            } else {
                (t->bal)++;
            }
        }
    }

    if(t->bal == 2) {
        if(t->dir->bal > 0) return rotEsq(T);
        else return doubleRotEsq(T);

    } else if(t->bal == -2) {
        if(t->esq->bal < 0) return rotDir(T);
        else return doubleRotDir(T);
    } else {

    } return verif;
}

int buscarChave(ArvoreAVL *T, int chave) {
    if(T == NULL) return -1; // Arvore Vazia

    if(T->chave == chave) return chave;

    else if(T->chave > chave) {
        if(T->esq == NULL) return T->chave;
        else return buscarChave(T->esq, chave);
    }

    else {
        if(T->dir == NULL) return T->chave;
        else return buscarChave(T->dir, chave);
    }
}

int removerChave(ArvoreAVL **T, ArvoreAVL **pai, int chave) {
    if(*T == NULL) return 0; // nada para remover;

    ArvoreAVL *t = *T;
    int verif = 0;

    if(t->chave == chave) {
        if(t->esq == NULL && t->dir == NULL) {
           
            if((*pai)->chave > chave) {
                (*pai)->esq = NULL;
                ((*pai)->bal)++;
            } else {
                (*pai)->dir = NULL;
                ((*pai)->bal)--;
            } free(t);

        } else if(t->esq == NULL) {
           
            if((*pai)->chave > chave) {
                (*pai)->esq = t->dir;
                ((*pai)->bal)++;
            } else {
                (*pai)->dir = t->dir;
                ((*pai)->bal)--;
            } free(t);
        
        } else if(t->dir == NULL) {
            
            if((*pai)->chave > chave) {
                (*pai)->esq = t->esq;
                ((*pai)->bal)++;
            } else {
                (*pai)->dir = t->esq;
                ((*pai)->bal)--;
            } free(t);

        } else {
            int newchave = buscarChave(t->esq, chave);
            removerChave(&((*T)->esq),T,newchave);
            (*T)->chave = newchave;
        } // Depois de remover temos que verificar qual o bal do Pai;

        if((*pai)->chave == 0) return 1;
        else return 3;

    } else if(t->chave > chave) {
        verif = removerChave(&(t->esq), T, chave);
        if(verif == 1) (t->bal)++;
    } else {
        verif = removerChave(&(t->dir), T, chave);
        if(verif == 1) (t->bal)--;
    }

    if(t->bal == 2) {
        if(t->dir->bal > 0) return rotEsq(T);
        else return doubleRotEsq(T);

    } else if(t->bal == -2) {
        if(t->esq->bal < 0) return rotDir(T);
        else return doubleRotDir(T);
    } else {

    } return verif;
}

void preordem(ArvoreAVL *T) {
    if(T) {
        printf("%d (%d) ", T->chave, T->bal);
        preordem(T->esq);
        preordem(T->dir);
    }
}

int rotEsq(ArvoreAVL **T) {
    ArvoreAVL *upper = *T;
    ArvoreAVL *lower = upper->dir;
    
    upper->bal = 0;
    lower->bal = 0;

    *T = lower;
    upper->dir = lower->esq;
    lower->esq = upper;

    return 2;
}

int rotDir(ArvoreAVL **T)  {
    ArvoreAVL *upper = *T;
    ArvoreAVL *lower = upper->esq;

    upper->bal = 0;
    lower->bal = 0;

    *T = lower;
    upper->esq = lower->dir;
    lower->dir = upper;

    return 2;
}

int doubleRotEsq(ArvoreAVL **T) {
    ArvoreAVL *upper = *T; 
    ArvoreAVL *lower = upper->dir; 
    ArvoreAVL *vvlow = lower->esq; 

    upper->bal = 0; 
    lower->bal = 0; 

    *T = vvlow; 
    upper->dir = vvlow->esq; 
    lower->esq = vvlow->dir; 
    vvlow->esq = upper; 
    vvlow->dir = lower; 

    return 2;
}

int doubleRotDir(ArvoreAVL **T) {
    ArvoreAVL *upper = *T;
    ArvoreAVL *lower = upper->esq;
    ArvoreAVL *vvlow = lower->dir;

    upper->bal = 0;
    lower->bal = 0;

    *T = vvlow;
    upper->esq = vvlow->dir;
    lower->dir = vvlow->esq;
    vvlow->dir = upper;
    vvlow->esq = lower;

    return 2;
}
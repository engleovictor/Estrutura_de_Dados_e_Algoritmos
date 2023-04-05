#include "arvore_binaria_de_busca.h"
#include <stdlib.h>
#include <stdio.h>

ArvoreBinaria *buscaArvoreBinariadeBusca(ArvoreBinaria *princ, ArvoreBinaria **pai, int chave) { 
    if(princ == NULL) return NULL;
    if(princ->chave == chave) {
        return princ;
    }
    else if(princ->chave > chave) {
        if(princ->esq != NULL) { 
            *pai = princ;
            return buscaArvoreBinariadeBusca(princ->esq,pai,chave);
        } else return princ;
    } else {
        if(princ->dir != NULL) {
            *pai = princ;
            return buscaArvoreBinariadeBusca(princ->dir,pai,chave);
        } else return princ;
    }
}

int inserirArvoreBinariadeBusca(ArvoreBinaria **princ, int chave) {
    ArvoreBinaria *pai = NULL;
    ArvoreBinaria *aux = buscaArvoreBinariadeBusca(*princ,&pai,chave);
    if(aux == NULL) {
        *princ = (ArvoreBinaria *) malloc(sizeof(ArvoreBinaria));
        (*princ)->dir = NULL;
        (*princ)->esq = NULL;
        (*princ)->chave = chave;
        return 1;
    } else {
        if(chave == aux->chave) return 0;
        if(chave > aux->chave) {
            aux->dir = (ArvoreBinaria *) malloc(sizeof(ArvoreBinaria));
            aux->dir->dir = NULL;
            aux->dir->esq = NULL;
            aux->dir->chave = chave;
            return 1;
        } else {
            aux->esq = (ArvoreBinaria *) malloc(sizeof(ArvoreBinaria));
            aux->esq->dir = NULL;
            aux->esq->esq = NULL;
            aux->esq->chave = chave;
            return 1;
        }
        return 1;
    }
}

int removeArvoreBinariadeBusca(ArvoreBinaria **princ, int chave) {
    ArvoreBinaria *pai = NULL;
    ArvoreBinaria *aux = buscaArvoreBinariadeBusca(*princ,&pai,chave);
    if(aux == NULL) return 0; // Arvore Vazia
    else {
        if(chave != aux->chave) return 0;
        if(aux->dir == NULL && aux->esq == NULL) {
            //removendo folha;
            if(pai == NULL) {
                //Avore Unitária
                *princ = NULL;
                free(aux);
            } else {
                //Arvore Não Unitária
                if(pai->chave > chave) {
                    pai->esq = NULL;
                    free(aux);
                } else {
                    pai->dir = NULL;
                    free(aux);
                }
            }
        } else if(aux->dir == NULL || aux->esq == NULL) {
            if(pai == NULL) {
                if((*princ)->chave > chave) *princ = aux->esq;
                else *princ = aux->esq;
                free(aux);
            } else {
                if(pai->chave > chave) {
                    // filho ta a esq do pai;
                    if(aux->dir == NULL) pai->esq = aux->esq;
                    else pai->esq = aux->dir;
                } else {
                    // caso contrario;
                    if(aux->dir == NULL) pai->dir = aux->esq;
                    else pai->dir = aux->dir;
                }
            }
        } else {
            //CASO ESQ E DIR != NULL (VAZIO);
            ArvoreBinaria *pai2 = NULL;
            ArvoreBinaria *aux2 = buscaArvoreBinariadeBusca(aux->esq,&pai2,chave);
            aux->chave = aux2->chave;
            removeArvoreBinariadeBusca(&pai2,aux->chave); // Por mais que faça a Busca novamente, ela faz em O(1);
        }
    }
    return 1;
}
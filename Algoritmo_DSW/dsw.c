#include "dsw.h"

void tornarArvoreLinear(ArvoreAVL **T) {
    while(*T != NULL && (*T)->esq != NULL) rotDir(T);
    if(*T) tornarArvoreLinear(&((*T)->dir));
}

int contarNos(ArvoreAVL *T) {
    int p = 0;
    contarNo_Abs(T, &p);
    return p;
}

void contarNo_Abs(ArvoreAVL *T, int *p) { // Abs é abstraido;
    if(T) {
        (*p)++;
        contarNo_Abs(T->dir,p);
        contarNo_Abs(T->esq,p);
    }
}

int minValToCheia(int n) {
    return pow(2,floor(log(n+1)/log(2))) - 1;
}

void tornarCompletaDeUmaLinear(ArvoreAVL **T) {
    int nos       = contarNos(*T);
    int make_full = minValToCheia(nos);

    // nos - make_full é qnt de operações que deve ser feita pra iniciar o processo geral;

    int val = nos - make_full;

    tornarCompleta_Abs(T,&val);


    while(1) {
        make_full = minValToCheia(make_full - 1);
        int new = make_full;
        if(!new) break;
        tornarCompleta_Abs(T,&new);
    }
}

void tornarCompleta_Abs(ArvoreAVL **T, int *p) {
    if(*T != NULL && *p > 0) {
        rotEsq(T);
        //printf("%d\n",*p);
        (*p)--;
        tornarCompleta_Abs(&((*T)->dir),p);
    }
}
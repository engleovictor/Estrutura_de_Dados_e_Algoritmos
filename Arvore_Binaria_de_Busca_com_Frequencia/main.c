#include <stdio.h>

#include "AVF.h"

int tam = 4;
int chaves[]   = {1,2,3,4};
int fchaves[]  = {10,3,1,2};
int nfchaves[] = {2,1,1,1,1};

int main() {
    int **matriz = matrizF(fchaves, nfchaves, tam);
    int ***dmatriz = matrizCC(chaves,fchaves,nfchaves,matriz,tam);
    ArvoreBinaria *T = montarComFreq(0,tam,chaves,dmatriz);
    printarPreOrdem(T);
    printf("\n");
    printarSimetric(T);
    printf("\n");
    return 0;
}
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

    for(int i=0;i<tam+1;i++) {
        for(int j=0;j<tam+1;j++) {
            printf("%d ", matriz[i][j]);
        } printf("\n");
    }

    printf("\n");

    for(int i=0;i<tam+1;i++) {
        for(int j=0;j<tam+1;j++) {
            printf("%d ", dmatriz[0][i][j]);
        } printf("\n");
    }

    printf("\n");

    for(int i=0;i<tam+1;i++) {
        for(int j=0;j<tam+1;j++) {
            printf("%d ", dmatriz[1][i][j]);
        } printf("\n");
    }

    printf("\n");

    printarPreOrdem(T);
    printf("\n");
    return 0;
}
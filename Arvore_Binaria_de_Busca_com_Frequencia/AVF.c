#include "AVF.h"
#include <stdlib.h>

int **matrizF(int *fchaves, int *nfchaves, int tam) {
    int **matriz = (int **) malloc(sizeof(int *)*(tam+1));
    for(int i=0;i<tam+1;i++) matriz[i] = (int *) malloc(sizeof(int)*(tam+1));

    for(int i=tam;i>-1;i--) {
        for(int j=0;j<tam+1;j++) {
            if(i > j) matriz[i][j] = 0;
            else if(i == j) matriz[i][j] = nfchaves[j]; // Estamos falando do Ri;
            else matriz[i][j] = matriz[i][j-1] + nfchaves[j] + fchaves[j-1]; // i < j, então ele vai e faz as operções de construção ''recursiva'';
        }
    }

    return matriz;
}

int ***matrizCC(int *chaves, int *fchaves, int *nfchaves, int **matrizF, int tam) {
    int ***doubleMatriz = (int ***) malloc(sizeof(int **)*(2));
    
    doubleMatriz[0] = (int **) malloc(sizeof(int *)*(tam+1));
    for(int i=0;i<tam+1;i++) doubleMatriz[0][i] = (int *) malloc(sizeof(int)*(tam+1));

    doubleMatriz[1] = (int **) malloc(sizeof(int *)*(tam+1));
    for(int i=0;i<tam+1;i++) doubleMatriz[1][i] = (int *) malloc(sizeof(int)*(tam+1));

    for(int i=tam;i>-1;i--) {
        for(int j=0;j<tam+1;j++) {
            if(i >= j) doubleMatriz[0][i][j] = 0;
            else if(i+1 == j) {
                doubleMatriz[0][i][j] = matrizF[i][j];
                doubleMatriz[1][i][j] = chaves[i];
            } else {
                int main_key, main_value = 2147483647; // Maior inteiro possivel;
                for(int k=i+1;k<j+1;k++) {
                    if(main_value > doubleMatriz[0][i][k-1] + doubleMatriz[0][k][j] + matrizF[i][j]) { // {> para 1° Arvore >= para a Ultima Arvore.}
                        main_value = doubleMatriz[0][i][k-1] + doubleMatriz[0][k][j] + matrizF[i][j];
                        main_key = chaves[k-1];
                    }
                }

                doubleMatriz[0][i][j] = main_value;
                doubleMatriz[1][i][j] = main_key;
            }
        }
    } return doubleMatriz;
}

ArvoreBinaria *montarComFreq(int lin, int col, int *chaves,int ***doubleMatriz) { // No começo para retornar a Arvore inicial devemos dar lin = 0, col = tam;
    if(lin == col) return NULL;
    else {
        ArvoreBinaria *newT = (ArvoreBinaria *) malloc(sizeof(ArvoreBinaria)*1);
        newT->chave = doubleMatriz[1][lin][col];
        int val = returnIndexKey(newT->chave, chaves);
        newT->esq = montarComFreq(lin,val-1,chaves,doubleMatriz);
        newT->dir = montarComFreq(val,col,chaves,doubleMatriz);
        return newT;
    } 
}

int returnIndexKey(int chave, int *p) {
    int i=0;
    while(p[i] != chave) i++;
    return ++i;
}
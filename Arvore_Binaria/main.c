#include <stdio.h>

#include "arvore_binaria.h"

int pre[] = {10,20,4,40,13};
int sim[] = {4,20,40,10,13};
int tam = 5;

int main() {
    ArvoreBinaria *mainTree = montarArPreSim(pre,sim,tam);
    printf("PREORDEM: ");
    printarPreOrdem(mainTree);
    printf("\n");
    printf("POSORDEM: ");
    printarPosOrdem(mainTree);
    printf("\n");
    printf("SIMETRICA: ");
    printarSimetric(mainTree);
    printf("\n");
    return 0;
}
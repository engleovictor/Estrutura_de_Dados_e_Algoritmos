#include <stdio.h>
#include <stdlib.h>

#include "arvore_binaria_de_busca.h"

int pre[] = {40,20,10,30,60,50,70};
int sim[] = {10,20,30,40,50,60,70};
int tam = 7;

int main() {
    ArvoreBinaria *princ = montarArPreSim(pre,sim,tam);
    inserirArvoreBinariadeBusca(&princ, 12);
    inserirArvoreBinariadeBusca(&princ, 3);
    inserirArvoreBinariadeBusca(&princ, 9);
    inserirArvoreBinariadeBusca(&princ, 4);
    inserirArvoreBinariadeBusca(&princ, 8);
    printarSimetric(princ);
    printf("\n");
    removeArvoreBinariadeBusca(&princ,4);
    printarSimetric(princ);
    printf("\n");
    printarPreOrdem(princ);
    printf("\n");
    removeArvoreBinariadeBusca(&princ,40);
    printarSimetric(princ);
    printf("\n");
    printarPreOrdem(princ);
    printf("\n");
    removeArvoreBinariadeBusca(&princ,70);
    printarSimetric(princ);
    printf("\n");
    printarPreOrdem(princ);
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

// int sim[] = {1,2,3,4,5,6};
// int pre[] = {2,1,5,4,3,6};
// int tam = 6;

int main() {
    ArvoreAVL *princ = NULL;
    inserirAVL(&princ,10);
    inserirAVL(&princ,20);
    inserirAVL(&princ,30);
    inserirAVL(&princ,40);
    inserirAVL(&princ,50);
    inserirAVL(&princ,60);
    inserirAVL(&princ,70);
    printarSimetricAVL(princ);
    printf("\n");
    printarPreOrdemAVL(princ);
    printf("\n");
    return 0;
}
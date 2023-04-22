#include <stdio.h>
#include <stdlib.h>

#include "avl.h"
#define safo {printarPreOrdemAVL(princ);printf("\n");}

// int sim[] = {1,2,3,4,5,6};
// int pre[] = {2,1,5,4,3,6};
// int tam = 6;

int main() {
    ArvoreAVL *pai   = NULL;
    ArvoreAVL *princ = NULL;
    inserirAVL(&princ,10);
    inserirAVL(&princ,20);
    inserirAVL(&princ,30);
    inserirAVL(&princ,40);
    inserirAVL(&princ,50);
    inserirAVL(&princ,60);
    inserirAVL(&princ,70);
    safo
    removerAVL(&princ,&pai,20);
    removerAVL(&princ,&pai,30);
    removerAVL(&princ,&pai,60);
    safo
    return 0;
}
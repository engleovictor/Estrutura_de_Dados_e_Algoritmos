#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int main() {
    ArvoreAVL *mainT = NULL;
    ArvoreAVL **pai = &mainT;
    inserirChave(&mainT, 30);
    inserirChave(&mainT, 10);
    inserirChave(&mainT, 20);
    inserirChave(&mainT, 40);
    inserirChave(&mainT, 50);
    inserirChave(&mainT, 60);
    inserirChave(&mainT, 70);
    preordem(mainT);
    printf("\n");
    removerChave(&mainT,pai,40);
    preordem(mainT);
    printf("\n");
    return 0;
}
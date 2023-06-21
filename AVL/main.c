#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int ins[] = {5,2,8,1,3,6,10,4,7,9,11,12};
int size = 12;

// int ins[] = {2,3,1};
// int size = 3;

int main() {
    ArvoreAVL *mainT = NULL;
    ArvoreAVL **pai = &mainT;
    for(int i=0;i<size;i++) inserirChave(&mainT, ins[i]);
    preordem(mainT);
    printf("\n");
    removerChave(&mainT,NULL,1);
    removerChave(&mainT,NULL,10);
    preordem(mainT);
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int ins[] = {20,40,60,80,100,10,30,120,130};
int size = 9;

int main() {
    ArvoreAVL *mainT = NULL;
    ArvoreAVL **pai = &mainT;
    for(int i=0;i<size;i++) {inserirChave(&mainT, ins[i]);
    preordem(mainT);
    printf("\n");}
    return 0;
}
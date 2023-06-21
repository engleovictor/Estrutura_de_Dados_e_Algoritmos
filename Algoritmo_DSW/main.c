#include <stdio.h>
#include "dsw.h"

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
    inserirChave(&mainT, 80);

    //for(int i=1;i<50001;i++) inserirChave(&mainT,i);

    tornarArvoreLinear(&mainT);

    preordem(mainT);
    printf("\n");
    //int p = contarNos(mainT);
    //printf("%d %d\n", p, minValToCheia(p));

    tornarCompletaDeUmaLinear(&mainT);

    preordem(mainT);
    printf("\n");

    return 0;
}
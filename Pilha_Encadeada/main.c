#include <stdio.h>

#include "pilha_encadeada.h"

int main() {
    Pilha_Enc *lista = NULL;
    pushenc(10,&lista);
    printarPilha(&lista);
    pushenc(20,&lista);
    printarPilha(&lista);
    pushenc(30,&lista);
    printarPilha(&lista);
    pushenc(40,&lista);
    printarPilha(&lista);
    printf("%d\n", popenc(&lista));
    printf("%d\n", popenc(&lista));
    printf("%d\n", popenc(&lista));
    printf("%d\n", popenc(&lista));
    printf("%d\n", popenc(&lista));
    return 0;
}
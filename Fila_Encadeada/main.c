#include <stdio.h>

#include "fila_encadeada.h"

int main() {
    Fila_Enc *lista = NULL;
    insercaoFilaEnc(10,&lista);
    printarFila(&lista);
    insercaoFilaEnc(20,&lista);
    printarFila(&lista);
    insercaoFilaEnc(30,&lista);
    printarFila(&lista);
    insercaoFilaEnc(40,&lista);
    printarFila(&lista);
    printf("%d\n", remocaoFilaEnc(&lista));
    printf("%d\n", remocaoFilaEnc(&lista));
    printf("%d\n", remocaoFilaEnc(&lista));
    printf("%d\n", remocaoFilaEnc(&lista));
    printf("%d\n", remocaoFilaEnc(&lista));
    return 0;
}
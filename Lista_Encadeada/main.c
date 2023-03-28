#include <stdio.h>

#include "lista_encadeada.h"

int main() {
    Lista_Enc *lista = NULL;
    insercaoListaEnc(10,&lista);
    printarLista(&lista);
    insercaoListaEnc(20,&lista);
    printarLista(&lista);
    insercaoListaEnc(30,&lista);
    printarLista(&lista);
    remocaoListaEnc(30,&lista);
    printarLista(&lista);
    remocaoListaEnc(10,&lista);
    printarLista(&lista);
    remocaoListaEnc(20,&lista);
    printarLista(&lista);
    return 0;
}
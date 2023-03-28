#include "pilha.h"

void push(int chave, int *lista, int *tam) {
    lista[*tam] = chave;
    (*tam)++;
}

int pop(int *lista, int *tam) {
    if(!(*tam)) return -1;
    (*tam)--;
    return lista[*tam];
}
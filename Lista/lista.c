#include "lista.h"

int buscaLista(int chave, int *lista, int tam) {
    int i = 0;
    while(i != tam && lista[i] != chave) i++;
    return i; // if(i == tam) não foi encontrado; 
}

int remocaoLista(int chave, int *lista, int *tam) {
    int i = buscaLista(chave,lista,*tam);
    if(i == *tam) return 0; // chave não foi encontrada;
    (*tam)--;
    while(i != *tam) {
        lista[i] = lista[i+1];
        i++;
    }
    return 1;
}

int insercaoLista(int chave, int *lista, int *tam) {
    int i = buscaLista(chave,lista,*tam);
    if(i != *tam) return 0; // achou a chave;
    (*tam)++;
    lista[*tam - 1] = chave;
    return 1; 
}

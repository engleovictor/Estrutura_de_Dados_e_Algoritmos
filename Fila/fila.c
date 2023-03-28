#include "fila.h"

int insercaoFila(int chave, int *lista, int tam, int *beg, int *end) {
    if(*beg == tam && *end == tam) { // Não tem ninguem na lista;
        *beg = *end = 0;
        lista[0] = chave;
        return 1;
    } else {
        if((*end+1)%tam == *beg) return 0; // Fila cheia;
        else {
           *end = (*end+1)%tam;
           lista[*end] = chave;
           return 1;
        }
    }
}

int remocaoFila(int *lista, int tam, int *beg, int *end) {
    if(*beg == tam && *end == tam) return -1; // Não há ninguem na fila
    if(*end == *beg) { // Fila unitaria
        int aux = lista[*beg];
        *end = *beg = tam;
        return aux;
        
    } else {
        int aux = lista[*beg];
        *beg = (*beg+1)%tam;
        return aux;
    }
}

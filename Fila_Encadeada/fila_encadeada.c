#include "fila_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

int insercaoFilaEnc(int chave, Fila_Enc **head) {
    Fila_Enc *new = (Fila_Enc *) malloc(sizeof(Fila_Enc));
    new->chave = chave;
    new->prox  = *head;
    *head = new;
    return 1;
}

int remocaoFilaEnc(Fila_Enc **head) {
    if(!(*head)) return -1; // Fila vazia
    if(!((*head)->prox)) {  // Fila Unitária
        int val = (*head)->chave;
        (*head) = NULL;
        return val;
    }
    Fila_Enc *aux = *head;
    while(aux->prox->prox) aux = aux->prox;
    int val = aux->prox->chave;
    aux->prox = NULL;
    return val;    
}

void printarFila(Fila_Enc **head) {
    if(!(*head)) return ;
    else {
        Fila_Enc *iter = *head;
        while(iter) {
            printf("%d, ",iter->chave);
            iter = iter->prox;
        } printf("\n");
    } return ;
}
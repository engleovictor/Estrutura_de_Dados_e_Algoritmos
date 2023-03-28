#include "pilha_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

int pushenc(int chave, Pilha_Enc **head) {
    Pilha_Enc *new = (Pilha_Enc *) malloc(sizeof(Pilha_Enc));
    new->chave = chave;
    new->prox  = *head;
    *head = new;
    return 1;
}

int popenc(Pilha_Enc **head) {
    Pilha_Enc *aux = *head;
    if(!aux) return -1; // Pilha vazia
    *head = aux->prox;
    int val = aux->chave;
    free(aux);
    return val;    
}

void printarPilha(Pilha_Enc **head) {
    if(!(*head)) return ;
    else {
        Pilha_Enc *iter = *head;
        while(iter) {
            printf("%d, ",iter->chave);
            iter = iter->prox;
        } printf("\n");
    } return ;
}
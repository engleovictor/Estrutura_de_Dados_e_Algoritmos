#include "lista_encadeada.h"
#include <stdlib.h>
#include <stdio.h>

Lista_Enc *buscaListEnc(int chave, Lista_Enc **head) {
    if(!(*head)) return NULL; // Lista Vazia;
    Lista_Enc *iter = *head;
    while(iter != NULL && iter->chave != chave) iter = iter->prox;
    return iter;     
}

int insercaoListaEnc(int chave, Lista_Enc **head) {
    Lista_Enc *aux = buscaListEnc(chave, head);
    if(!aux) {
        Lista_Enc *new = (Lista_Enc *) malloc(sizeof(Lista_Enc));
        new->chave = chave;
        new->prox  = *head;
        *head = new;
        return 1;
    } // Chave Não encontrada ou Lista Vazia;
    return 0;
}

int remocaoListaEnc(int chave, Lista_Enc **head) {
    Lista_Enc *aux = *head;
    if(!aux) return 0;
    if(aux->chave == chave) {
        *head = (*head)->prox;
        free(aux);
        return 1;
    }
    while(aux->prox != NULL && aux->prox->chave != chave) aux = aux->prox;
    if(aux->prox)
    aux->prox = aux->prox->prox;
    return 1;
}

void printarLista(Lista_Enc **head) {
    if(!(*head)) return ;
    else {
        Lista_Enc *iter = *head;
        while(iter) {
            printf("%d, ",iter->chave);
            iter = iter->prox;
        } printf("\n");
    } return ;
}
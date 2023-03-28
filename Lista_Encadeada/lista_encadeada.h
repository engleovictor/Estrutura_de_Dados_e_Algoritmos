#ifndef _LISTA_ENCADEADA_H_
#define _LISTA_ENCADEADA_H_

typedef struct lista_encadeada {
    int chave;
    struct lista_encadeada *prox;
} Lista_Enc;

Lista_Enc *buscaListEnc(int chave, Lista_Enc **head);
int insercaoListaEnc(int chave, Lista_Enc **head);
int remocaoListaEnc(int chave, Lista_Enc **head);
void printarLista(Lista_Enc **head);

#endif /* _LISTA_ENCADEADA_H_ */
#ifndef _FILA_ENCADEADA_H_
#define _FILA_ENCADEADA_H_

typedef struct fila_encadeada {
    int chave;
    struct fila_encadeada *prox;
} Fila_Enc;

int insercaoFilaEnc(int chave, Fila_Enc **head);
int remocaoFilaEnc(Fila_Enc **head);
void printarFila(Fila_Enc **head);

#endif /* _FILA_ENCADEADA_H_ */
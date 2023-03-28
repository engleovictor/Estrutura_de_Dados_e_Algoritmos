#ifndef _PILHA_ENCADEADA_H_
#define _PILHA_ENCADEADA_H_

typedef struct pilha_encadeada {
    int chave;
    struct pilha_encadeada *prox;
} Pilha_Enc;

int pushenc(int chave, Pilha_Enc **head);
int popenc(Pilha_Enc **head);
void printarPilha(Pilha_Enc **head);

#endif /* _PILHA_ENCADEADA_H_ */
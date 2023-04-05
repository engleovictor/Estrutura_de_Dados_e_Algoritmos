#ifndef _ARVORE_BINARIA_DE_BUSCA_H_
#define _ARVORE_BINARIA_DE_BUSCA_H_

#include "../Arvore_Binaria/arvore_binaria.h"

ArvoreBinaria *buscaArvoreBinariadeBusca(ArvoreBinaria *princ, ArvoreBinaria **pai, int chave);
int inserirArvoreBinariadeBusca(ArvoreBinaria **princ, int chave);
int removeArvoreBinariadeBusca(ArvoreBinaria **princ, int chave);
 
#endif // _ARVORE_BINARIA_DE_BUSCA_
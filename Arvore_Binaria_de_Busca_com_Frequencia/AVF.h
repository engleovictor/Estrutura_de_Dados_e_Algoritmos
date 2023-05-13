#ifndef _AVF_H_
#define _AVF_H_

#include "../Arvore_Binaria_de_Busca/arvore_binaria_de_busca.h"

// funcs!
int **matrizF(int *fchaves, int *nfchave, int tam);
int ***matrizCC(int *chaves, int *fchaves, int *nfchaves, int **matrizF, int tam);
ArvoreBinaria *montarComFreq(int lin, int col, int *chaves, int ***doubleMatriz);
int returnIndexKey(int chave, int *p);
#endif // _AVF_H_
#include "../AVL/avl.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void tornarArvoreLinear(ArvoreAVL **T);
int contarNos(ArvoreAVL *T);
void contarNo_Abs(ArvoreAVL *T, int *p); // Abs de Abstraido;
int minValToCheia(int n);
void tornarCompletaDeUmaLinear(ArvoreAVL **T);
void tornarCompleta_Abs(ArvoreAVL **T, int *p);
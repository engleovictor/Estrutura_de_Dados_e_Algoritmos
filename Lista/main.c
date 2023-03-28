#include <stdio.h>

#include "lista.h"

int lista[1000];
int tam = 0;

int main() {
    insercaoLista(10,lista,&tam);
    insercaoLista(20,lista,&tam);
    insercaoLista(30,lista,&tam);
    insercaoLista(40,lista,&tam);
    for(int i=0;i<tam;i++) {
        printf("%d, ", lista[i]);
    } printf("\n");
    int busc[] = {10, 50, 20};
    printf("%d, %d, %d\n", buscaLista(busc[0],lista,tam), buscaLista(busc[1],lista,tam), buscaLista(busc[2],lista,tam));
    remocaoLista(20,lista,&tam);
    remocaoLista(30,lista,&tam);
    for(int i=0;i<tam;i++) {
        printf("%d, ", lista[i]);
    } printf("\n");
    return 0;
}
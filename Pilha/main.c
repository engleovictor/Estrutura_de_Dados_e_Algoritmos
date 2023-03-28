#include <stdio.h>

#include "pilha.h"

int lista[1000];
int tam = 0;

int main() {
    push(10,lista,&tam);
    push(20,lista,&tam);
    push(30,lista,&tam);
    push(40,lista,&tam);
    for(int i=0;i<tam;i++) {
        printf("%d, ", lista[i]);
    } printf("\n");
    //                            // Esse foi exec primeiro
    printf("%d, %d\n", pop(lista,&tam), pop(lista,&tam));
    for(int i=0;i<tam;i++) {
        printf("%d, ", lista[i]);
    } printf("\n");
    return 0;
}
#include <stdio.h>

#include "fila.h"

#define tam 5

int lista[5];
int beg = tam, end = tam;

int main() {
    insercaoFila(10,lista,tam,&beg,&end);
    printf("%d %d\n", beg, end);
    insercaoFila(20,lista,tam,&beg,&end);
    printf("%d %d\n", beg, end);
    insercaoFila(30,lista,tam,&beg,&end);
    printf("%d %d\n", beg, end);
    insercaoFila(40,lista,tam,&beg,&end);
    printf("%d %d\n", beg, end);
    printf("%d\n", remocaoFila(lista,tam,&beg,&end));
    printf("%d %d\n", beg, end);
    insercaoFila(50,lista,tam,&beg,&end);
    printf("%d %d\n", beg, end);
    insercaoFila(60,lista,tam,&beg,&end);
    printf("%d %d\n", beg, end);
    insercaoFila(70,lista,tam,&beg,&end);
    printf("%d %d\n", beg, end);
    printf("%d\n", remocaoFila(lista,tam,&beg,&end));
    printf("%d %d\n", beg, end);
    printf("%d\n", remocaoFila(lista,tam,&beg,&end));
    printf("%d %d\n", beg, end);
    printf("%d\n", remocaoFila(lista,tam,&beg,&end));
    printf("%d %d\n", beg, end);
    printf("%d\n", remocaoFila(lista,tam,&beg,&end));
    printf("%d %d\n", beg, end);
    printf("%d\n", remocaoFila(lista,tam,&beg,&end));
    printf("%d %d\n", beg, end);
    printf("%d\n", remocaoFila(lista,tam,&beg,&end));
    printf("%d %d\n", beg, end);
    return 0;
}
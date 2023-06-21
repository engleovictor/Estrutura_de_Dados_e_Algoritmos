#include <stdio.h>

#include "arvoreb.h"

int vals[] = {1,3,5,7,9};

int main() {
    //ArvoreB  *hop = newSubtree(3);
    int x = buscaBinaria(vals,5,2);
    printf("%d\n", vals[x]);
    return 0;
}
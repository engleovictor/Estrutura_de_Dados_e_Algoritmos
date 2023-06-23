#include "heap.h"

int main() {
    int size = 0;
    int heap[25];
    
    inserir(heap,&size,3);
    inserir(heap,&size,32);
    inserir(heap,&size,23);
    inserir(heap,&size,13);
    inserir(heap,&size,4);
    inserir(heap,&size,2);
    inserir(heap,&size,1);
    inserir(heap,&size,22);
    mostrar_heap(heap,size);
    return 0;
}
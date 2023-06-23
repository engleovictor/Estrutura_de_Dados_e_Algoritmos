#include "heap.h"

void inserir(int *heap, int *size, int elem) {
    heap[(*size)++] = elem;
    subir(heap, *size-1);
}

int remover(int *heap, int *size) {
    int a = heap[0];
    heap[0] = heap[--(*size)];
    heap[*size+1] = a; // Essa linha é só pra fazer HEAPSORT;
    descer(heap,*size,0);
    return a;
}

int acessar(int *heap) {
    return heap[0];
}

void subir(int *heap, int last) {
    if(heap[last] > heap[(last-1)/2] && last > 0) {
        int a = heap[last];
        heap[last] = heap[(last-1)/2];
        heap[(last-1)/2] = a;
        subir(heap, (last-1)/2);
    } return ;
}

void descer(int *heap, int size, int pos) {
    if(pos >= size/2) return ; // É folha;
    
    else if(pos == size/2 - 1 && size%2 == 0) { // Possui apenas um filho;
        if(heap[pos] < heap[2*pos+1]) { // Então troca;
            int a = heap[pos];
            heap[pos] = heap[2*pos+1];
            heap[2*pos+1] = a;
            // Nessa posição nova não há filhos;
            return ;
        }

    } else {

        int val = (heap[2*pos+1]>heap[2*pos+2]?2*pos+1:2*pos+2);

        if(heap[pos] < heap[val]) { // Então troca;
            
            int a = heap[pos];
            heap[pos] = heap[val];
            heap[val] = a;
            descer(heap,size,val);

        } else return ;
    }
    
}

void mostrar_heap(int *heap, int size) {
    for(int i=0;i<size;i++) {
        printf("%d ", heap[i]); 
    } printf("\n");
}
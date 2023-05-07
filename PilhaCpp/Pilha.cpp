#include "Pilha.h"

Pilha::Pilha():
size(0), max_size(2), vals(new int[max_size]) {

}

Pilha::Pilha(const Pilha &p):
size(p.size), max_size(p.max_size), vals(new int[max_size]) {
    for(int i=0;i<size;i++) vals[i] = p.vals[i];
}

void Pilha::resize(bool mode) {
    // if mode == 1 -> aumentar tamanho;
    if(mode) {
        max_size *= 2;
        int *new_vals = new int[max_size];
        for(int i=0;i<size;i++) new_vals[i] = vals[i];
        delete[] vals;
        vals = new_vals;
    } else {
        max_size /= 2;
        int *new_vals = new int[max_size];
        for(int i=0;i<size;i++) new_vals[i] = vals[i];
        delete[] vals;
        vals = new_vals;
    }
}

bool Pilha::inserir(int val) {
    if(size == max_size) resize(1);
    vals[size++] = val;
    return true;
}

int Pilha::remover() {
    if(size < 1) return -1; // Pilha vazia
    else {
        int old_val = vals[--size];
        if(size+1 == max_size/2 && max_size > 2) resize(0);
        return old_val; 
    }
}

string Pilha::mostrarPilha() {
    string str_vals = "";
    str_vals += "[";
    for(int i=0;i<size;i++) {
        str_vals += std::to_string(vals[i]);
        if(i < size-1) str_vals += " ";
    }
    str_vals += "]";
    return str_vals;
}
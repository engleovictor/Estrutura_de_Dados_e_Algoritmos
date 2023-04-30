#include "Deque.h"

Deque::Deque(int max_size):
max_size(max_size), size(0), inicio(max_size), finl(max_size), vals(new int[max_size]) {}

Deque::Deque(const Deque &d):
max_size(d.max_size), size(d.size), inicio(d.inicio), finl(d.finl), vals(new int[d.max_size]) {
    for(int i=0;i<size;i++) vals[(inicio+i)%max_size] = d.vals[(inicio+i)%max_size];
}

bool Deque::inserirInicio(int val) {
    if(size == max_size) return false;
    else {
        size++;
        if(inicio == max_size) {
            inicio  = 0;
            finl    = 0;
            vals[0] = val;
        } else {
            inicio--;
            if(inicio == -1) inicio = max_size - 1;
            vals[inicio] = val;
        } return true;
    }
}

bool Deque::inserirFinal(int val) {
    if(size == max_size) return false;
    else {
        size++;
        if(inicio == max_size) {
            inicio  = 0;
            finl    = 0;
            vals[0] = val;
        } else {
            finl = (finl+1)%max_size;
            vals[finl] = val;
        }
    } return true;
}

string Deque::pegarElementos() {
    string mid = "";
    for(int i=0;i<size;i++) {
        mid += std::to_string(vals[(i+inicio)%max_size]);
        if(i < size - 1) mid += " ";
    } return "{" + mid + "}";
}

int Deque::removerInicio() {
    if(size == 0) return -1;
    int val = vals[inicio];
    size--;
    if(size == 0) {
        inicio = max_size;
        finl   = max_size;
    } else {
        inicio = (inicio+1)%max_size;
    } return val;
}

int Deque::removerFinal() {
    if(size == 0) return -1;
    int val = vals[finl];
    size--;
    if(size == 0) {
        inicio = max_size;
        finl   = max_size;
    } else {
        finl--;
        if(finl == -1) finl = max_size - 1;
    } return val;
}
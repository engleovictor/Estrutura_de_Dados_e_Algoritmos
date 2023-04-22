#include "Arvore_Binaria.h"

ArvoreBinaria::ArvoreBinaria(int chave)
:chave(chave) {
    this->esq = nullptr;
    this->dir = nullptr;
}

int ArvoreBinaria::pegarChave() {
    return chave;
}

string ArvoreBinaria::preordem() {
    string beg = "", mid = "", end = "";
    beg = std::to_string(this->chave);
    if(this->esq != nullptr) mid = this->esq->preordem();
    if(this->dir != nullptr) end = this->dir->preordem();
    
    if(mid == "" && end == "") return beg;
    else if(mid == "") return beg + " " + end;
    else if(end == "") return beg + " " + mid;
    else return beg + " " + mid + " " + end;
}

bool ArvoreBinaria::inserirEsquerda(ArvoreBinaria *T) {
    if(this->esq == nullptr) {
        this->esq == T;
        return true;
    } else return false;
}

bool ArvoreBinaria::inserirDireita(ArvoreBinaria *T) {
    if(this->dir == nullptr) {
        this->dir == T;
        return true;
    } else return false;
}

ArvoreBinaria *ArvoreBinaria::pegarDireita() {
    return dir;
}
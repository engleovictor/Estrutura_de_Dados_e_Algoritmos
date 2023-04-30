#include "Fila.h"

bool Fila::inserir(int val) {
    return this->Deque::inserirFinal(val);
}

int Fila::remover() {
    return this->Deque::removerInicio();
}
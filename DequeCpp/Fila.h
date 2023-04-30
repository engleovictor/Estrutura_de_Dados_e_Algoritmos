#ifndef _FILA_HPP_
#define _FILA_HPP_

#include "Deque.h"

class Fila: public Deque {
    bool inserirInicio(int val);
    bool inserirFinal(int val);
    int removerInicio();
    int removerFinal();
    
    public:
        Fila(int qnt): Deque(qnt) {}
        Fila(const Fila &f): Deque(f) {}
        bool inserir(int val);
        int remover();
};


#endif // _FILA_HPP_
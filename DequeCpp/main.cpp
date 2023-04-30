#include <iostream>
#include "Deque.h"
#include "Fila.h"

using namespace std;

int main() {
    // Deque deque(5);

    // deque.inserirFinal(20);
    // deque.inserirFinal(30);
    // deque.inserirFinal(40);
    // deque.inserirInicio(10);
    // deque.inserirInicio(50);

    // cout << deque.removerFinal() << endl;

    // cout << deque.pegarElementos() << endl;

    Fila fila(5);

    fila.inserir(10);
    fila.inserir(20);
    fila.inserir(30);
    fila.inserir(40);
    fila.inserir(50);
    fila.inserir(60);

    cout << fila.pegarElementos() << endl;

    cout << fila.remover() << endl;

    cout << fila.pegarElementos() << endl;

    return 0;
}

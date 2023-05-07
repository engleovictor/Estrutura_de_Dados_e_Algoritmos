#include <iostream>

#include "Pilha.h"

using namespace std;

int main() {
    Pilha P;
    cout << P.mostrarPilha() << endl; // É pra mostrar a pilha vazia;
    P.inserir(10); // Insere o 10 na pilha;
    cout << P.mostrarPilha() << endl;
    P.inserir(15);
    P.inserir(20);
    P.inserir(25);
    P.inserir(30);
    P.inserir(35);
    cout << P.mostrarPilha() << endl; // Mostra todos os adicionados;
    cout << P.remover() << endl; // Remove e mostra o que removeu;
    P.remover();
    P.remover();
    P.remover();
    P.remover();
    cout << P.mostrarPilha() << endl;
    cout << P.remover() << endl;
    cout << P.remover() << endl; // Mostra -1, pois ja removeu tudo;
    
    return 0;
}
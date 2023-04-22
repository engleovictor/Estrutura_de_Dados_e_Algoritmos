#include <iostream>

using std::cout;

#include "Arvore_Binaria.h"

int main() {
    ArvoreBinaria T(10);
    ArvoreBinaria *n2 = new ArvoreBinaria(20);
    ArvoreBinaria *n3 = new ArvoreBinaria(30);
    ArvoreBinaria *n4 = new ArvoreBinaria(40);

    cout << T.inserirDireita(n4) << n4->inserirDireita(n3) << n4->inserirDireita(n2);

    cout << T.preordem() << std::endl;
    cout << T.pegarDireita()->preordem() << std::endl;
    
    
    return 0;
}

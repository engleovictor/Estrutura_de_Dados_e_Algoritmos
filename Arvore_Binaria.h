#ifndef _ARVORE_BINARIA_
#define _ARVORE_BINARIA_

#include <string>

using std::string;

class ArvoreBinaria {
    protected:
        int chave;

    public:
        ArvoreBinaria *esq, *dir;
        ArvoreBinaria(int chave);
        int pegarChave();
        string preordem();
        bool inserirEsquerda(ArvoreBinaria *T);
        bool inserirDireita(ArvoreBinaria *T);
        ArvoreBinaria *pegarDireita();
}; 

#endif
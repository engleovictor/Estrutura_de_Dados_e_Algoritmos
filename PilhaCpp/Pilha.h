#ifndef _PILHA_H_
#define _PILHA_H_

#include <string>

using std::string;

class Pilha {
    int size;
    int max_size;
    int *vals;
    void resize(bool mode);

    public:
        Pilha(); // Construtor Padrão;
        Pilha(const Pilha &p); // Construtor por cópia; MUITO IMPOTANTE;
        ~Pilha() { // Muito importante para não haver memory leak;
            delete[] vals;
        }
        bool inserir(int val);
        int remover();
        string mostrarPilha();
};

#endif // _PILHA_H_
#ifndef _DEQUE_HPP_
#define _DEQUE_HPP_

#include <string>

using std::string;

class Deque {
    int max_size;
    int size;
    int *vals;
    int inicio;
    int finl;

    public:
        Deque(int max_size);
        Deque(const Deque &d);
        bool inserirInicio(int val);
        bool inserirFinal(int val);
        string pegarElementos();
        int removerInicio();
        int removerFinal();
        
        ~Deque() {
            delete[] vals;
        }
}; 


#endif // _DEQUE_HPP_
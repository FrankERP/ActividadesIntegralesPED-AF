//
// Arbol.h
//

#ifndef ABB_NEW_ARBOL_H
#define ABB_NEW_ARBOL_H
#include <vector>
#include "Nodo.cpp"
using namespace std;

template <class T>
class Arbol {
public:
    Arbol();
    ~Arbol();
    bool add(T);
    bool search(T);
    void visit(int);
    void levelByLevel();
    int height();
    void ancestors(T key);
    int whatLevelAmI(T);

private:
    shared_ptr <Nodo<T>> raiz;
};


#endif //ABB_NEW_ARBOL_H

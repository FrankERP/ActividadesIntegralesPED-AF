//
// Nodo.h
//

#ifndef ABB_NEW_NODO_H
#define ABB_NEW_NODO_H

#include <memory>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Arbol;

template<class T>
class Nodo: public enable_shared_from_this<Nodo<T>>{
private:
    shared_ptr<Nodo<T>> left;
    shared_ptr<Nodo<T>> right;
    shared_ptr<Nodo<T>> father;
    T key;
public:
    friend class Arbol<T>;
    bool add(T);
    shared_ptr<Nodo<T>> search(T);
    void preOrder();
    void inOrder();
    void postOrder();
    int height();
    shared_ptr<Nodo<T>> getFather();
    int getNumAncestors();
    shared_ptr<Nodo<T>> suc();
    shared_ptr<Nodo<T>> pre();
    Nodo();
    ~Nodo();

};


#endif //ABB_NEW_NODO_H

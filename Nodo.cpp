//
// Nodo.cpp
//

#include "Nodo.h"

template<class T>
Nodo<T>::Nodo(){

}
template <class T>
Nodo <T>::~Nodo(){}

template <class T>
bool Nodo<T>::add(T k){  // O(log(n)) donde n es el nivel del nodo.
    if(k == key)
        return false;
    if (k < key){
        if (left == nullptr){
            left = make_shared<Nodo<T>>();
            left -> key = k;
            left -> father = this -> shared_from_this();
            return true;
        }
        return left -> add(k);
    }
    if (right == nullptr){
        right = make_shared<Nodo<T>>();
        right -> key = k;
        right -> father = this -> shared_from_this();
        return true;
    }
    return right -> add(k);
}

template <class T>
shared_ptr<Nodo<T>> Nodo<T>::search(T k) { // O(log(n)) donde n es el nivel del nodo.
    if (k == key){
        return this -> shared_from_this();
    }
    if (k < key){
        if(left == nullptr){
            return nullptr;
        }
        return left -> search(k);
    }
    if (right == nullptr){
        return nullptr;
    }
    return right -> search(k);
}

template<class T>
void Nodo<T>::preOrder(){ // O(n) donde n es el número de nodos.
    cout << key << endl;
    if (left != nullptr){
        left -> preOrder();
    }
    if (right !=  nullptr){
        right -> preOrder();
    }
}


template<class T>
void Nodo<T>::inOrder(){ // O(n) donde n es el número de nodos.
    if (left != nullptr){
        left -> inOrder();
    }
    cout << key << endl;
    if (right !=  nullptr){
        right -> inOrder();
    }
}

template <class T>
void Nodo<T>::postOrder(){ // O(n) donde n es el numero de nodos
    if (left != nullptr){
        left -> postOrder();
    }
    if (right !=  nullptr){
        right -> postOrder();
    }
     cout << key << endl;
}



template <class T>
int Nodo<T>::height(){ // O(log(n)) donde n es el total de nodos
    int heightLeft = -1;
    int heightRight = -1;
    if(left != nullptr){
        heightLeft = left -> height();
    }
    if (right != nullptr){
        heightRight = right -> height();
    }
    return max(heightLeft, heightRight) + 1;
}

template <class T>
shared_ptr<Nodo<T>> Nodo<T>::getFather(){ // O(1)
    return this -> father;
}
template <class T>
int Nodo<T>::getNumAncestors(){ // O(n) donde n es el nivel del nodo.
    int count = 0;
    if (this -> father != nullptr){
        count++;
        count += this -> father -> getNumAncestors();
    }
    return count;
}



template <class T>
shared_ptr<Nodo<T>> Nodo<T>::suc() {
    shared_ptr<Nodo<T>> m = right;
    if(m == nullptr) {
        if(father->left == this->shared_from_this()) {
            return father;
        }
        else {    
            return nullptr;
        }
    }
    while(m->left != nullptr) {
        m = m->left;
    }
    return m;
}

template <class T>
shared_ptr<Nodo<T>> Nodo<T>::pre() {
    shared_ptr<Nodo<T>> m = left;
    if(m == nullptr) {
        if(father->right == this->shared_from_this()) {
            return father;
        }
        else {    
            return nullptr;
        }
    }
    while(m->right != nullptr) {
        m = m->right;
    }
    return m;
}

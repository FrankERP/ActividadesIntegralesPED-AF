//
// Arbol.cpp 
//

#include "Arbol.h"

template <class T>
Arbol<T>::Arbol(){}

template <class T>
Arbol<T>::~Arbol(){}

template <class T>
bool Arbol<T>::add(T key) { // O(log(n)) donde n es el nivel del nodo.
    if (raiz == nullptr){
        raiz = make_shared<Nodo<T>>();
        raiz -> key = key;
        return true;
    }
    return raiz -> add(key);
}

template <class T>
bool Arbol<T>::search(T key){ // O(log(n)) n es el nivel del nodo.
    if (raiz != nullptr){
        shared_ptr<Nodo<T>> node = raiz -> search(key);
        return node != nullptr;
    }
    return false;
}


template <class T>
int Arbol<T>::height(){ // O(log(n)) donde n es 
    if (raiz == nullptr){
        return -1;
    }
    return raiz -> height();
}

template <class T>
void Arbol<T>::ancestors(T key){ // O(n)
    
    if (raiz != nullptr){
        if (raiz -> key == key){
            cout << "No hay ancestros de este Nodo.\n";
            return;
        }
        shared_ptr<Nodo<T>> node = raiz -> search(key);
        if (node != nullptr){
            cout << "Los ancestros del nodo " << key << " son: \n";
            while (node != raiz){
                cout << node -> getFather() -> key << endl;
                node = node -> getFather();
            } 
            return;
        }
    }
    cout << "Dato no encontrado." << endl;
}

template <class T>
int Arbol<T>::whatLevelAmI(T key){ // O(n) donde n es el nivel del nodo. 
    if (raiz != nullptr){
        shared_ptr<Nodo<T>> node = raiz -> search(key);
        return node -> getNumAncestors(); //O(n)
    }
    return -1;
}
template <class T>
void Arbol<T>::levelByLevel(){ // O(n) donde n es el número de nodos
  
    if (raiz != nullptr){
        vector<shared_ptr<Nodo<T>>> temp;
        temp.push_back(raiz);
        temp.push_back(nullptr);
        bool empty = false;
        while (!empty){
            shared_ptr<Nodo<T>> nodo = temp.front();
            temp.erase(temp.begin());
            if (nodo != nullptr){
                cout << nodo -> key << " , ";
                if (nodo -> left != nullptr){
                    temp.push_back(nodo -> left);
                }
                if (nodo -> right != nullptr){
                    temp.push_back(nodo->right);
                }
            }else {
                cout << endl;
                if (temp.empty()) empty = true;
                temp.push_back(nullptr);
            }
        }
    }
}

template<class T>
void Arbol<T>::visit(int mode){ // O(n) donde n es el número de nodos
    if (raiz!=nullptr){
        switch(mode) {
        case 1: // Preorder
            cout << "Visualización en preOrder:" << endl; 
            raiz -> preOrder(); // O(n) 
            break;
        case 2: // Inorder
            cout << "Visualización en inOrder:" << endl; 
            raiz -> inOrder(); // O(n)
            break;
        case 3: // Postorder
            cout << "Visualización en postOrder:" << endl; 
            raiz -> postOrder();  // O(n)
            break;
        case 4: //Level by level
            cout << "Visualización en levelByLevel:" << endl; 
            this -> levelByLevel(); // O(n)
            break;
        default :
            cout << "Modo de búsqueda no identificado." << endl;
        }
    }
}
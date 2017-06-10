//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#include "Iterator.h"

template<class TElement>
Iterator<TElement>::Iterator(BST<TElement> *bst): bst{ bst } {

    //Initialsie the stack
    Node<TElement> *aux = this->bst->getRoot();
    while(aux != nullptr) {
        this->st.push(aux);
        aux = aux->left;
    }

    this->crt = this->st.top();
    this->next();
}

template<class TElement>
TElement Iterator<TElement>::getInfo() {
    return this->crt->info;
}

template<class TElement>
Node<TElement> *Iterator<TElement>::getNode() {
    return this->crt;
}

template<class TElement>
bool Iterator<TElement>::valid() {
    return this->crt != nullptr;
}

template<class TElement>
void Iterator<TElement>::next() {
    if(st.empty()) {
        this->crt = nullptr;
        return;
    }

    this->crt = this->st.top(); this->st.pop();

    Node<TElement> *aux = this->crt;
    if(aux->right == nullptr)
        return;

    aux = aux->right;
    while(aux != nullptr) {
        this->st.push(aux);
        aux = aux->left;
    }
}

template class Iterator<int>;
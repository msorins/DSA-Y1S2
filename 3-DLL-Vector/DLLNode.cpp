//
// Created by Sorin Sebastian Mircea on 01/05/2017.
//

#include <MacTypes.h>
#include "DLLNode.h"


template<class TElement>
DLLNode<TElement>::DLLNode() {
    this->info = NULL;
    this->next = -1;
    this->prev = -1;
}


template<class TElement>
void DLLNode<TElement>::setInfo(TElement info) {
    this->info = info;
}

template<class TElement>
void DLLNode<TElement>::setNext(int next) {
    this->next = next;
}

template<class TElement>
void DLLNode<TElement>::setPrev(int prev) {
    this->prev = prev;
}

template<class TElement>
TElement DLLNode<TElement>::getInfo() const {
    return this->info;
}

template<class TElement>
int DLLNode<TElement>::getNext() const {
    return this->next;
}

template<class TElement>
int DLLNode<TElement>::getPrev() const {
    return this->prev;
}


template class DLLNode<int>;
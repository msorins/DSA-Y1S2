//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#include "Node.h"

template<class TElement>
Node<TElement>::Node() {
    this->info = NULL;
    this->left = this->right = nullptr;
}


template<class TElement>
Node<TElement>::Node(TElement info): Node() {
    this->info = info;
}


template class Node<int>;
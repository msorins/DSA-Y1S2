//
// Created by Sorin Sebastian Mircea on 09/06/2017.
//

#include "InOrderRecursive.h"

template<class TElement>
InOrderRecursive<TElement>::InOrderRecursive(Heap<TElement> *heap) {
    this->heap = heap;
    this->crtNodePost = 0;
    this->computeOrderList(this->heap->getRootNode());
}

template<class TElement>
TElement InOrderRecursive<TElement>::getInfo() {
    return this->list[this->crtNodePost]->info;
}

template<class TElement>
Node<TElement> *InOrderRecursive<TElement>::getNode() {
    return this->list[this->crtNodePost];
}

template<class TElement>
void InOrderRecursive<TElement>::next() {
    this->crtNodePost++;
}

template<class TElement>
bool InOrderRecursive<TElement>::valid() {
    return this->crtNodePost < this->list.size();
}

template<class TElement>
void InOrderRecursive<TElement>::computeOrderList(Node<TElement> *node) {
    this->list.push_back(node);

    if(node->st != nullptr) this->computeOrderList(node->st);
    if(node->dr != nullptr) this->computeOrderList(node->dr);

}


template class InOrderRecursive<int>;
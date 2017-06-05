//
// Created by Sorin Sebastian Mircea on 22/05/2017.
//

#include "HashMapIterator.h"

template<class TElement>
HashMapIterator<TElement>::HashMapIterator(HashMap<TElement> *map) {
    this->map = map;
    this->currentHash = 1;

    while(this->map->getNullElements()[this->currentHash] == true)
        this->currentHash++;
}

template<class TElement>
TElement HashMapIterator<TElement>::getCurrent() {
    return this->map->getElems()[this->currentHash];
}

template<class TElement>
void HashMapIterator<TElement>::next() {
    this->currentHash++;
    while(this->map->getNullElements()[this->currentHash] == true)
        this->currentHash++;
}

template<class TElement>
bool HashMapIterator<TElement>::valid() {
    return this->currentHash >= 1 && this->currentHash <= this->map->getHashValue();
}

template class HashMapIterator< Elem<string, int> >;
template class HashMapIterator< Elem<int, int> >;
template class HashMapIterator< Elem<double, double> >;
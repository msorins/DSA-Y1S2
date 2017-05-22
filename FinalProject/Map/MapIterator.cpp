//
// Created by Sorin Sebastian Mircea on 22/05/2017.
//

#include "MapIterator.h"
#include "../HashMap/HashMapIterator.h"

template<class TElement>
MapIterator<TElement>::MapIterator(Map<TElement> *map) {

    this->map = map;

    this->hashMapIt = new HashMapIterator< Elem<TElement> >(this->map->getElemsRef());
}

template<class TElement>
Elem<TElement> MapIterator<TElement>::getCurrent() {
    Elem<TElement> x = this->hashMapIt->getCurrent();
    return x;
}

template<class TElement>
void MapIterator<TElement>::next() {
    this->hashMapIt->next();
}

template<class TElement>
bool MapIterator<TElement>::valid() {
    return this->hashMapIt->valid();
}

template class MapIterator<int>;
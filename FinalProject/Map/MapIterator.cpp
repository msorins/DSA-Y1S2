//
// Created by Sorin Sebastian Mircea on 22/05/2017.
//

#include "MapIterator.h"
#include "../HashMap/HashMapIterator.h"

template<class TKey, class TElement>
MapIterator<TKey, TElement>::MapIterator(Map<TKey, TElement> *map) {

    this->map = map;

    this->hashMapIt = new HashMapIterator< Elem<TKey, TElement> >(this->map->getElemsRef());
}

template<class TKey, class TElement>
Elem<TKey, TElement> MapIterator<TKey, TElement>::getCurrent() {
    Elem<TKey, TElement> x = this->hashMapIt->getCurrent();
    return x;
}

template<class TKey, class TElement>
void MapIterator<TKey, TElement>::next() {
    this->hashMapIt->next();
}

template<class TKey, class TElement>
bool MapIterator<TKey, TElement>::valid() {
    return this->hashMapIt->valid();
}

template class MapIterator<string, int>;
template class MapIterator<int, int>;
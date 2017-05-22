//
// Created by Sorin Sebastian Mircea on 21/05/2017.
//

#include "Map.h"
#include "../Exception/Exception.h"

template<class TKey, class TElement>
Map<TKey, TElement>::Map(int m) {
    this->m = m;
    this-> elems = new HashMap< Elem<TKey, TElement> >(m);
}

template<class TKey, class TElement>
HashMap<Elem<TKey, TElement> > Map<TKey, TElement>::getElems() {
    return *this->elems;
}

template<class TKey, class TElement>
HashMap<Elem<TKey, TElement> > *Map<TKey, TElement>::getElemsRef() {
    return this->elems;
}

template<class TKey, class TElement>
void Map<TKey, TElement>::add(TKey key, TElement value) {
    //Check to see if the key-value pair is not already in the container
    if(this->search(key, value))
        throw Exception("Element already in map");

    Elem<TKey, TElement> el(key, value);
    this->elems->insert(el);
}

template<class TKey, class TElement>
bool Map<TKey, TElement>::remove(TKey key) {
    //Check to see if the key-value pair is not already in the container
    if(!this->search(key, NULL))
        return false;

    Elem<TKey, TElement> el(key, NULL);
    this->elems->remove(el);
    return true;
}

template<class TKey, class TElement>
bool Map<TKey, TElement>::search(TKey key, TElement value) {

    Elem<TKey, TElement> el(key, NULL);
    return this->elems->find(el);
}

template<class TKey, class TElement>
int Map<TKey, TElement>::size() {
    return this->elems->getSize();
}


template class Map<string, int>;
template class Map<int, int>;
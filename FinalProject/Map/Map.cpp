//
// Created by Sorin Sebastian Mircea on 21/05/2017.
//

#include "Map.h"
#include "../Exception/Exception.h"

template<class TElement>
Map<TElement>::Map(int m) {
    this->m = m;
    this-> elems = new HashMap< Elem<TElement> >(m);
}

template<class TElement>
HashMap<Elem<TElement> > Map<TElement>::getElems() {
    return *this->elems;
}

template<class TElement>
HashMap<Elem<TElement> > *Map<TElement>::getElemsRef() {
    return this->elems;
}

template<class TElement>
void Map<TElement>::add(string key, TElement value) {
    //Check to see if the key-value pair is not already in the container
    if(this->search(key, value))
        throw Exception("Element already in map");

    Elem<TElement> el(key, value);
    this->elems->insert(el);
}

template<class TElement>
bool Map<TElement>::remove(string key) {
    //Check to see if the key-value pair is not already in the container
    if(!this->search(key, NULL))
        return false;

    Elem<TElement> el(key, NULL);
    this->elems->remove(el);
    return true;
}

template<class TElement>
bool Map<TElement>::search(string key, TElement value) {

    Elem<TElement> el(key, NULL);
    return this->elems->find(el);
}

template<class TElement>
int Map<TElement>::size() {
    return this->elems->getSize();
}


template class Map<int>;
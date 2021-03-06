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
    if(this->find(key))
        throw Exception("Element already in map");

    Elem<TKey, TElement> el(key, value);
    this->elems->insert(el);
}

template<class TKey, class TElement>
bool Map<TKey, TElement>::erase(TKey key) {
    //Check to see if the key-value pair is not already in the container
    if(!this->find(key))
        return false;

    Elem<TKey, TElement> el(key, NULL);
    this->elems->remove(el);
    return true;
}

template<class TKey, class TElement>
bool Map<TKey, TElement>::find(TKey key) {

    Elem<TKey, TElement> el(key, NULL);
    return this->elems->find(el);
}

template<class TKey, class TElement>
int Map<TKey, TElement>::size() {
    return this->elems->getSize();
}

template<class TKey, class TElement>
Elem<TKey, TElement> Map<TKey, TElement>::get(TKey key) {
    int hashPos = this->elems->findPos( Elem<TKey, TElement>(key, NULL) );
    if(hashPos == -1)
        return Elem<TKey, TElement>(NULL, NULL);

    return this->elems->getElems()[hashPos];
}


template class Map<string, int>;
template class Map<int, int>;
template class Map<double, double>;
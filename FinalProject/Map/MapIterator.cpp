//
// Created by Sorin Sebastian Mircea on 07/05/2017.
//

#include "MapIterator.h"
#include <iostream>
#include <string>
using namespace std;

template<class TElement>
MapIterator<TElement>::MapIterator(Map<TElement> *container) {
    this->container = container;
    this->currentKeyPos = 1;
}

template<class TElement>
MapIterator<TElement>::~MapIterator() {

}

template<class TElement>
pair<string, TElement> MapIterator<TElement>::getCurrent() {
    return make_pair(this->container->getElems().getElement(this->currentKeyPos).key,
            this->container->getElems().getElement(this->currentKeyPos).el);
}

template<class TElement>
bool MapIterator<TElement>::isValid() {
    if( this-> currentKeyPos > this->container->getElems().size() )
        return false;

    return true;
}

template<class TElement>
void MapIterator<TElement>::next() {
    this->currentKeyPos++;
}

template class MapIterator<string>;
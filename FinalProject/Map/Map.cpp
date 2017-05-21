//
// Created by Sorin Sebastian Mircea on 21/05/2017.
//

#include "Map.h"

template<class TElement>
HashMap<Elem<TElement> > Map<TElement>::getElems() {
    return this->elems;
}

template<class TElement>
void Map<TElement>::add(string key, TElement value) {

}

template<class TElement>
bool Map<TElement>::remove(string key) {
    return false;
}

template<class TElement>
bool Map<TElement>::search(string key, TElement value) {
    return false;
}

template<class TElement>
int Map<TElement>::size() {
    return 0;
}

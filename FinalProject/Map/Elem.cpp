//
// Created by Sorin Sebastian Mircea on 07/05/2017.
//

#include "Elem.h"

template<class TElement>
Elem<TElement>::Elem(string key, TElement el) {
    this->key = key;
    this->el = el;
}

template class Elem<string>;
template class Elem<int>;


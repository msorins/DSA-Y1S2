//
// Created by Sorin Sebastian Mircea on 07/05/2017.
//

#include "Elem.h"

template<class TKey, class TElement>
Elem<TKey, TElement>::Elem(TKey key, TElement el) {
    this->key = key;
    this->el = el;
}

template<class TKey, class TElement>
Elem<TKey, TElement>::Elem() {

}


template class Elem<int, int>;
template class Elem<string, int>;


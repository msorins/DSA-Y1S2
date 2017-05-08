//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#include "SSETIterator.h"

template<class TElement>
SSETIterator<TElement>::SSETIterator(SSET<TElement> *st) {
    this->current = 1;
    this->set = st;
}

template<class TElement>
TElement SSETIterator<TElement>::getCurrent() {
    return this->set->getElems().getElement(this->current);
}

template<class TElement>
void SSETIterator<TElement>::next() {
    this->current++;
}

template<class TElement>
bool SSETIterator<TElement>::valid() {
    if(this->current <= this->set->size())
        return true;
    return false;
}

template class SSETIterator<int>;
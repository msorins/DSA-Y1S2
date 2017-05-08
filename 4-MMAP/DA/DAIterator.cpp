//
// Created by Sorin Sebastian Mircea on 30/04/2017.
//

#include "DAIterator.h"

template<class TElement>
DAIterator<TElement>::DAIterator(DA<TElement>* b) {
    this->bag = b;
    this->currentPos = 1;
}

template<class TElement>
TElement DAIterator<TElement>::getCurrent() {
    /*
     * DESC: returns the current element
     * PRE: iterator is valid
     * POST: element is returned
     */
    return this->bag->getElement( this->currentPos );
}

template<class TElement>
bool DAIterator<TElement>::valid() {
    /*
     * DESC: return True if iterator is valid, False otherwise
     * PRE: -
     * POST: -
     */
    return this->currentPos <= this->bag->size();
}

template<class TElement>
void DAIterator<TElement>::next() {
    /*
     * DESC: advances the iterator
     * PRE: -
     * POST: -
     */

    this->currentPos++;
}

template class DAIterator<int>;
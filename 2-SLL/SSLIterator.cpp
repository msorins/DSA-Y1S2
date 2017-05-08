//
// Created by Sorin Sebastian Mircea on 01/05/2017.
//

#include <MacTypes.h>
#include "SSLIterator.h"

template<class TElement>
SSLIterator<TElement>::SSLIterator(SSL<TElement> *ssl) {
    /*
     * CONSTRUCTOR
     */

    this->ssl = ssl;
    this->currentElement = ssl->head;
}

template<class TElement>
TElement SSLIterator<TElement>::getCurrent() {
    return this->currentElement->info;
}

template<class TElement>
void SSLIterator<TElement>::next() {
    this->currentElement = this->currentElement->next;
}

template<class TElement>
bool SSLIterator<TElement>::valid() {
    if(this->currentElement->info == NULL)
        return false;

    return true;

}

template class SSLIterator<int>;


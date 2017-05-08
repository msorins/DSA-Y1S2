//
// Created by Sorin Sebastian Mircea on 01/05/2017.
//

#ifndef INC_2_SLL_SLLITERATOR_H
#define INC_2_SLL_SLLITERATOR_H
#include "SSL.h"
#include "SSLNode.h"

template<class TElement>
class SSLIterator {
private:
    SSL<TElement> *ssl;
    SSLNode<TElement> *currentElement;
public:
    //Constructor
    SSLIterator(SSL<TElement> *ssl);

    //Functionality
    TElement getCurrent();
    void next();
    bool valid();
};

#endif //INC_2_SLL_SLLITERATOR_H

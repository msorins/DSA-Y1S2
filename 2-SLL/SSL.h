//
// Created by Sorin Sebastian Mircea on 01/05/2017.
//

#ifndef INC_2_SLL_SSL_H
#define INC_2_SLL_SSL_H

#include "SSLNode.h"

template<class TElement>
class SSL {
public:
    SSLNode<TElement>* head;

public:
    //Functionality
    void insertFirst(TElement el);
    void insertAfter(SSLNode<TElement> &node, TElement el);
    void insertAtPosition(int pos, TElement el);
    SSLNode<TElement> deleteFirst();
    SSLNode<TElement> deleteByValue(TElement el);
    SSLNode<TElement> * search(TElement el);

};



#endif //INC_2_SLL_SSL_H

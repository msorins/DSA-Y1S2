//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#ifndef INC_07_BST_ITERATOR_H
#define INC_07_BST_ITERATOR_H

#include "../BST/BST.h"
#include <iostream>
#include <stack>
using namespace std;

template<class TElement>
class Iterator {
private:
    BST< TElement > *bst;
    stack< Node<TElement>* > st;
    Node<TElement> *crt;
public:
    //Constructor
    Iterator(BST< TElement > *bst);

    //Functionality
    TElement getInfo();
    Node<TElement>* getNode();
    bool valid();
    void next();
};



#endif //INC_07_BST_ITERATOR_H

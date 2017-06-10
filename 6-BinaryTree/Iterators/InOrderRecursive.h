//
// Created by Sorin Sebastian Mircea on 09/06/2017.
//

#ifndef INC_6_BINARYTREE_INORDER_H
#define INC_6_BINARYTREE_INORDER_H

#include "../Heap/Heap.h"
#include <vector>
#include <iostream>
using namespace std;

template<class TElement>
class InOrderRecursive {
private:
    Heap<TElement> *heap;
    int crtNodePost;
    vector< Node<TElement>* > list;

public:
    //Constructor
    InOrderRecursive(Heap<TElement> *heap);

    //Functionality
    TElement getInfo();
    Node<TElement>* getNode();
    void next();
    bool valid();

private:
    void computeOrderList(Node<TElement> *node);
};



#endif //INC_6_BINARYTREE_INORDER_H

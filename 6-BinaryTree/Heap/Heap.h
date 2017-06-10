//
// Created by Sorin Sebastian Mircea on 09/06/2017.
//

#ifndef INC_6_BINARYTREE_BINARYTREE_H
#define INC_6_BINARYTREE_BINARYTREE_H

#include "../Node/Node.h"
#include <iostream>
#include <queue>

using namespace std;
template<class TElement>
class Heap {
private:
    Node<TElement> *root;
    Node<TElement> *lastNode;
    queue< Node<TElement>* > q;

public:
    //Constructors
    Heap();
    Heap(TElement info);
    /*
    Heap(Node<TElement>* node);
    Heap(Node<TElement>* st, TElement info, Node<TElement> *dr);
     */

    //Destructor
    ~Heap();

    //Functionality
    void insert(TElement info);
    void remove(TElement info);
    bool exists(TElement info);
    TElement getTop();
    Node<TElement> *getRootNode();

private:
    void shift(Node<TElement>* node);
    void percolate(Node<TElement>* node);
    void chooseLastNode();

};




#endif //INC_6_BINARYTREE_BINARYTREE_H

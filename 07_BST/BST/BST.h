//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#ifndef INC_07_BST_BST_H
#define INC_07_BST_BST_H


#include "../Node/Node.h"

template <class TElement>
class BST {
private:
    Node<TElement> *root;

public:
    //Constructor
    BST();

    //Destructor
    ~BST();

    //Functionality
    void insert(TElement info);
    void remove(TElement info);
    bool search(TElement info);
    Node<TElement> *getRoot();
};



#endif //INC_07_BST_BST_H

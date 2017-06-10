//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#include "BST.h"

template<class TElement>
BST<TElement>::BST() {
    this->root = nullptr;
}

template<class TElement>
BST<TElement>::~BST() {
    /*
     * Also have to make sure the rest of the nodes are deleted
     */
    delete this->root;
}

template<class TElement>
void BST<TElement>::insert(TElement info) {
    /*
     * insert a new element in the BST
     */

    Node<TElement> *crt = this -> root;
    Node<TElement> *last = nullptr;
    bool right = false;

    //Find the position on which the element needs to be inserted
    while( crt != nullptr ) {
        last = crt;

        if(info > crt->info)
            crt = crt->right, right = true;
        else
            crt = crt->left, right = false;
    }

    //Create the element that is going to be added
    Node<TElement> *newNode = new Node<TElement>;
    newNode->info = info;

    //Add the element (If BST already contain info)
    if(last != nullptr) {
        if(right)
            last->right = newNode;
        else
            last->left = newNode;
    }
    else //If BST is empty
        this->root = newNode;
}


template<class TElement>
void BST<TElement>::remove(TElement info) {

}


template<class TElement>
bool BST<TElement>::search(TElement info) {
    Node<TElement> *crt = this -> root;

    while(crt != nullptr && crt->info != info) {
        if(info > crt->info)
            crt = crt->right;
        else
            crt = crt -> left;
    }

    return crt != nullptr;
}

template<class TElement>
Node<TElement> *BST<TElement>::getRoot() {
    return this->root;
}


template class BST<int>;
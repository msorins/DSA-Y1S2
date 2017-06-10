//
// Created by Sorin Sebastian Mircea on 09/06/2017.
//

#include "Heap.h"
#include "../Iterators/InOrderRecursive.h"

template<class TElement>
Heap<TElement>::Heap() {
    this->root = new Node<TElement>;
    this->root->father = this->root->st = this->root->dr = NULL;
    this->lastNode = root;
}

template<class TElement>
Heap<TElement>::Heap(TElement info): Heap() {
    this->root->info = info;
}

/*
template<class TElement>
Heap<TElement>::Heap(Node<TElement> *node) {
    this->root = node;
}

template<class TElement>
Heap<TElement>::Heap(Node<TElement> *st, TElement info, Node<TElement> *dr): Heap() {
    this->root->st = st;
    this->root->dr = dr;
    this->root->info = info;
}
*/

template<class TElement>
Heap<TElement>::~Heap() {
    delete this->root;
}

template<class TElement>
void Heap<TElement>::insert(TElement info) {
    //IF the element is empty
    if(this->lastNode->info == NULL) {
        this->lastNode->info = info;
        return ;
    }

    //If left part is empty
    if(this->lastNode->st == nullptr) {
        this->lastNode->st = new Node<TElement>;
        this->lastNode->st->st = this->lastNode->st->dr = NULL; this->lastNode->st->father = this->lastNode;
        this->lastNode->st->info = info;

        this->percolate(this->lastNode->st);
        return;
    }

    //If right part is empty
    if(this->lastNode->dr == nullptr) {
        this->lastNode->dr = new Node<TElement>;
        this->lastNode->dr->st = this->lastNode->dr->dr = NULL; this->lastNode->dr->father = this->lastNode;
        this->lastNode->dr->info = info;

        this->percolate(this->lastNode->dr);
        return;
    }

    //If Neither of them are null
    this->lastNode = this->lastNode->st;
    this->lastNode->st = new Node<TElement>;
    this->lastNode->st->st = this->lastNode->st->dr = NULL; this->lastNode->st->father = this->lastNode;


    this->lastNode = this->lastNode->st;
    this->lastNode->info = info;

    this->percolate(this->lastNode);
    this->chooseLastNode();
    return;

}

template<class TElement>
void Heap<TElement>::remove(TElement info) {
    /*
     * TO DO WHEN I HAVE THE ITERATOR
     */

}

template<class TElement>
bool Heap<TElement>::exists(TElement info) {
    /*
     * TO DO WHEN I HAVE THE ITERATOR
     */
    return false;
}

template<class TElement>
TElement Heap<TElement>::getTop() {
    return this->root->info;
}

template<class TElement>
void Heap<TElement>::shift(Node<TElement> *node) {
    /*
     * devansam un nod in jos
     */
    while(node->info < node->st->info || node->info < node->dr->info) {
        if(node->info < node->st->info) {
            swap(node->info, node->st->info);
            node = node->st;
            continue;
        }

        if(node->info < node->dr->info) {
            swap(node->info, node->dr->info);
            node = node->dr;
            continue;
        }
    }
}

template<class TElement>
void Heap<TElement>::percolate(Node<TElement> *node) {
    /*
     * avansam un nod in sus
     */
    while(node->father != nullptr && node->info > node->father->info) {
        swap(node->info, node->father->info);
        node = node->father;
    }

}

template<class TElement>
Node<TElement> *Heap<TElement>::getRootNode() {
    return this->root;
}

template<class TElement>
void Heap<TElement>::chooseLastNode() {
    /*
     * lazy bad solution
     */
    InOrderRecursive<TElement> it(this);
    Node<TElement> *el;
    while(it.valid()) {
        el = it.getNode();
        if(el->dr == nullptr)
            break;
        it.next();
    }

    this->lastNode = el;
}

template class Heap<int>;
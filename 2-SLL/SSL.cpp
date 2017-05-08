//
// Created by Sorin Sebastian Mircea on 01/05/2017.
//

#include "SSL.h"
#include <iostream>
using namespace std;

template<class TElement>
void SSL<TElement>::insertFirst(TElement el) {
    /*
     * DESCR: Inserts a new node at a begining
     * PRE: SSL is valid, EL is TElement
     * POST: el is inserted into SSL
     */
    //Allocate a new SSL NODe
    SSLNode<TElement>* newNode = new SSLNode<TElement>();
    newNode->info = el;
    newNode->next = this->head;

    //Put it as the first
    this->head = newNode;
}

template<class TElement>
void SSL<TElement>::insertAfter(SSLNode<TElement> &node, TElement el) {
    /*
     * DESCR: Inserts a new node after a specific node
     * PRE: SSL is valid, NODE is a valid SSLNODE
     * POST: NODE is inserted into SSL
     */

    //Create the new node
    SSLNode<TElement>* newNode =  new SSLNode<TElement>();
    newNode->info = el;
    newNode->next = node.next;

    node.next = newNode;
}

template<class TElement>
void SSL<TElement>::insertAtPosition(int pos, TElement el) {
    /*
     * DESCR: insert at a custom position the element EL
     * PRE: pos is an integer >= 1, SSL is a valid SSL
     * POST: SSL with element inserted
     */

    if(pos < 1) {
        throw("Invalid index given");
    }

    if(pos == 1) {
        this->insertFirst(el);
        return;
    }

    int crtPos = 1;
    SSLNode<TElement>* crtNode =  new SSLNode<TElement>();
    crtNode = this->head;

    //Loop through the insert position
    while(crtPos < pos - 1) {
        if(crtNode -> next == nullptr) {
            throw("Invalid index (too big)");
        }

        crtNode = crtNode->next;
        crtPos++;
    }

    //Create a new node with the current element
    this->insertAfter(*crtNode, el);
}

template<class TElement>
SSLNode<TElement> SSL<TElement>::deleteFirst() {
    /*
     * DESCR: Deletes the first element from SSL
     * PRE: SSL is a valid non-empty SSL
     * POST: first element is deleted
     */

    if (this->head->next == nullptr) {
        throw ("SSL empty");
    }

    SSLNode<TElement> *firstNode = this->head;
    SSLNode<TElement> *secondNode = this->head->next;

    delete (this->head);
    this->head = secondNode;

    return *firstNode;
}

template<class TElement>
SSLNode<TElement> SSL<TElement>::deleteByValue(TElement el) {
    /*
     * DESCR:
     * PRE:
     * POST:
     */

    SSLNode<TElement>* crtNode = this->head;
    SSLNode<TElement>* prevNode = this->head;
    SSLNode<TElement> foundNode;

    if(this->head->info == el) {
        foundNode = *this->head;
        this->deleteFirst();
        return foundNode;
    }

    while(crtNode->info != el) {
        if(crtNode->next == nullptr)
            throw("Element does not exist");

        prevNode = crtNode;
        crtNode = crtNode->next;
    }

    foundNode = *crtNode;
    prevNode->next = crtNode->next;
    delete crtNode;

    return foundNode;
}

template<class TElement>
SSLNode<TElement> * SSL<TElement>::search(TElement el) {
    /*
     * DESCR:
     * PRE:
     * POST:
     */

    SSLNode<TElement>* crtNode = this->head;

    while(crtNode->info != el) {
        if(crtNode->next == nullptr)
            throw("Element does not exist");

        crtNode = crtNode->next;
    }

    return crtNode;
}


template class SSL<int>;
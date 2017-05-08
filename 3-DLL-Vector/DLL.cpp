//
// Created by Sorin Sebastian Mircea on 01/05/2017.
//

#include <MacTypes.h>
#include "DLL.h"

template<class TElement>
DLL<TElement>::DLL() {
    this->head = -1;
    this->tail = -1;
}

template<class TElement>
int DLL<TElement>::getHead() const {
    return head;
}

template<class TElement>
void DLL<TElement>::setHead(int head) {
    this->head = head;
}

template<class TElement>
int DLL<TElement>::getTail() const {
    return tail;
}

template<class TElement>
void DLL<TElement>::setTail(int tail) {
    this->tail = tail;
}

template<class TElement>
int DLL<TElement>::getFirstEmpty() const {
    return firstEmpty;
}

template<class TElement>
void DLL<TElement>::setFirstEmpty(int firstEmpty) {
    this->firstEmpty = firstEmpty;
}

template<class TElement>
void DLL<TElement>::insertFirst(TElement el) {
    /*
     * DESC: insert a new element on first position
     * PRE: el is a valid TElement
     * POST: new DLL with element inserted
     */
    this->allocate();

    //the DLL is empty
    if(this->firstEmpty == 1) {
        DLLNode<TElement> newElem(el, -1, -1);
        this->nodes.setElement(this->firstEmpty, newElem);
        this->head = firstEmpty;
        this->tail = firstEmpty;
    }
    else {
        //Update the previous head
        DLLNode<TElement> crtHead = this->nodes.getElement(this->head);
        crtHead.setPrev(this->firstEmpty);
        this->nodes.setElement(this->head, crtHead);


        //Add the new node as head
        this->nodes.setElement(this->firstEmpty, DLLNode<TElement>(el, -1, this->head));
        this->head = this->firstEmpty;
    }

}

template<class TElement>
void DLL<TElement>::insertAtPosition(int pos, TElement el) {
    this->allocate();

    int crtIndex = this->head;
    int prevIndex = -1;
    int crtPos = 1;
    while( crtPos < pos ) {
        if(crtIndex == -1)
            throw("Error at inserting element");

        prevIndex = crtIndex;
        crtIndex = this->nodes.getElement(crtIndex).getNext();
        crtPos += 1;
    }

    //Set previous element
    DLLNode<TElement> prevElem = this->nodes.getElement(prevIndex);
    prevElem.setNext(this->firstEmpty);
    this->nodes.setElement(prevIndex, prevElem);

    //Set next element
    DLLNode<TElement> nextElem = this->nodes.getElement(crtIndex);
    nextElem.setPrev(this->firstEmpty);
    this->nodes.setElement(crtIndex, nextElem);

    //Add the element
    this->nodes.addToPosition(this->firstEmpty, DLLNode<TElement>(el, prevIndex, crtIndex ));
}

template<class TElement>
TElement DLL<TElement>::deleteFirst() {
    if(this->head == -1)
        throw("DLL already empty");

     TElement deletetEl = this->nodes.getElement(this->head).getInfo();

    int auxHead = this->head;
    int newHead = this->nodes.getElement(this->head).getNext();
    this->deallocate(auxHead);
    this->head = newHead;

    return deletetEl;
}

template<class TElement>
TElement DLL<TElement>::deleteByValue(TElement el) {

    DLLNode<TElement> crtEl = this->search(el);

    //If the TElement is not found
    if(crtEl.getInfo() == NULL )
        return NULL;

    //Otherwise, if it is found
    if(crtEl.getPrev() != -1) {
        DLLNode<TElement> prevEl = this->nodes.getElement( crtEl.getPrev() );
        prevEl.setNext( crtEl.getNext() );
        this->nodes.setElement(crtEl.getPrev(), prevEl);
    } else {
        //It is the first element
        return this->deleteFirst();
    }
    if(crtEl.getNext() != -1) {
        DLLNode<TElement> nextEl = this->nodes.getElement( crtEl.getNext() );
        nextEl.setPrev( crtEl.getPrev() );
        this->nodes.setElement(crtEl.getNext(), nextEl);
    }

    //Free that node
    //this->deallocate()
    return crtEl.getInfo();
}

template<class TElement>
TElement DLL<TElement>::deleteByPosition(int pos) {
    int crtIndex = this->head;
    int prevIndex = -1;
    int nextIndex = -1;

    int crtPos = 1;
    if(pos == 1) {
        return this->deleteFirst();
    }


    while( crtPos < pos ) {
        if(crtIndex == -1)
            throw("Error at inserting element");

        prevIndex = crtIndex;
        crtIndex = this->nodes.getElement(crtIndex).getNext();
        crtPos += 1;
    }
    nextIndex = this->nodes.getElement(crtIndex).getNext();

    //Set previous element
    DLLNode<TElement> prevElem = this->nodes.getElement(prevIndex);
    prevElem.setNext(nextIndex);
    this->nodes.setElement(prevIndex, prevElem);

    //Set the deleted element
    TElement deletetEl = this->nodes.getElement(crtIndex).getInfo();

    //Set next element
    if(nextIndex != -1) {
        DLLNode<TElement> nextElem = this->nodes.getElement(nextIndex);
        nextElem.setPrev(prevIndex);
        this->nodes.setElement(nextIndex, nextElem);
    }


    //Add the element
    this->deallocate(crtIndex);

    return deletetEl;
}

template<class TElement>
DLLNode<TElement> DLL<TElement>::search(TElement el) {
    int crtIndex = this->head;
    int crtPos = 1;

    //Loop through all nodes
    while( this->nodes.getElement(crtIndex).getInfo() != NULL && this->nodes.getElement(crtIndex).getInfo() != el ) {
        if(crtIndex == -1)
            throw("Error at inserting element");

        crtIndex = this->nodes.getElement(crtIndex).getNext();
        crtPos += 1;
    }

    //If it is not found
    if(this->nodes.getElement(crtIndex).getInfo() == NULL)
        return DLLNode<TElement>(NULL, -1, -1);

    //If it is found
    DLLNode<TElement> foundEl = this->nodes.getElement(crtIndex);
    return foundEl;
}


template<class TElement>
int DLL<TElement>::allocate() {
    //Check if one of the nodes are empty to take its place
    for(int i = 1; i <= this->nodes.size(); i++) {
        if(this->nodes.getElement(i).getInfo() == NULL && this->nodes.getElement(i).getPrev() == -1 && this->nodes.getElement(i).getNext() == -1) {
            this->firstEmpty = i;
            return i;
        }
    }

    //Create a new empty node
    DLLNode<TElement> x;
    this->nodes.addToEnd(x);
    this->firstEmpty = this->nodes.size();


    return this->nodes.size();
}

template<class TElement>
void DLL<TElement>::deallocate(int pos) {
    DLLNode<TElement> crt = this->nodes.getElement(pos);
    crt.setInfo(NULL);
    crt.setPrev(-1);
    crt.setNext(-1);
    this->nodes.setElement(pos, crt);
}


/*
 *
 *         1        2          3          4           5          6          7
 *   -------------------------------------------------------------------------
 *   INFO:     INFO:     INFO:     INFO:     INFO:     INFO:     INFO:
 *   n:   p:  |  n:   p: |  n:   p: | n:   p: |   n:   p: |   n:   p:  |
 *
 *   cap=-1
 */

template class DLL<int>;
template class DA< DLLNode<int> >;
//
// Created by Sorin Sebastian Mircea on 19/05/2017.
//

#include "HashMap.h"
#include "../Exception/Exception.h"


template<class TElement>
HashMap<TElement>::HashMap(int m) {

    this->size = 0;
    this->m = m;

    this->elems.reserve(m + 1);
    this->next.reserve(m + 1);

    for(int i = 0; i < m; i++) {
        this->elems.push_back(NULL);
        this->next.push_back(0);
    }

    nextFree = m-1;
}

template<class TElement>
void HashMap<TElement>::insert(TElement el) {
    /*
     *
     */

    //Check to see if the container is not already full
    if(this->size == this->m)
        throw Exception("Container full");

    //Do the hashing (to get the index for the array)
    int hash = this->hash(el);

    //If item slot is not occupied
    if(this->elems[hash] == NULL) {
        this->elems[hash] = el; 
        return;
    }
    
    //We must find another free slot to put the elment
    while(this->next[hash] != 0)
        hash = this->next[hash];

    //Assign it
    this->next[hash] = this->nextFree;
    this->elems[ this->nextFree ] = el;

    //Increase the number of elements that are in the container
    this->size++;

    //Assign a new free element
    this->assignNextFree();
}

template<class TElement>
bool HashMap<TElement>::remove(TElement el) {

    //Do the hashing (to get the index for the array)
    int hash = this->hash(el);
    int lastHash;

    //If the element that we are currently searching is the first and there is nobody chaining after him
    if(this->elems[hash] == el && this->next[hash] == 0) {
        this->elems[hash] = NULL;
        this->nextFree = max(this->nextFree, hash);
        return true;
    }

    //Find the element we are searching for
    while(this->elems[hash] != el) {
        if(this->next[hash] == 0)
            return false;

        lastHash = hash;
        hash = this->next[hash];
    }

    this->next[lastHash] = this->next[hash];

    //We found it ... now delete it
    this->elems[hash] = 0;
    this->nextFree = max(this->nextFree, hash);

    //And move all chained elements one step before
    while(this->next[hash] != 0) {
        this->elems[hash] = this->elems[ this->next[hash] ];
        this->next[hash] = this->next[ this->next[hash] ];
        hash = this->next[hash];
    }

    return true;
}

template<class TElement>
int HashMap<TElement>::hash(int el) {
    return el % this->m;
}

template<class TElement>
void HashMap<TElement>::assignNextFree() {
    while(this->nextFree >= 1 && this->elems[nextFree] != NULL)
        this->nextFree--;
}

template<class TElement>
vector<TElement> HashMap<TElement>::getElems() {
    return this->elems;
}

template<class TElement>
vector<int> HashMap<TElement>::getNexts() {
    return this->next;
}

template<class TElement>
bool HashMap<TElement>::find(TElement el) {
    /*
     * Returns true if the item exists, or folse otherwise
     */
    return this->findPos(el) != -1;
}

template<class TElement>
int HashMap<TElement>::findPos(TElement el) {

    //Do the hashing (to get the index for the array)
    int hash = this->hash(el);

    //If item slot is not occupied
    do {
        //We found th element (return the position)
        if(this->elems[hash] == el)
            return hash;

        //Else go to the next one

        //If it doesn't exist
        if(this->next[hash] == 0)
            return -1;

        //If it exists
            hash = this->next[hash];

    }while(true);
}


template class HashMap<int>;
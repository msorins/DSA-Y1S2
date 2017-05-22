//
// Created by Sorin Sebastian Mircea on 19/05/2017.
//

#include "HashMap.h"
#include "../Exception/Exception.h"
#include <vector>
#include <string>
using namespace std;

template<class TElement>
HashMap<TElement>::HashMap(int m) {

    this->size = 0;
    this->m = m;

    this->elems.reserve(m + 2);
    this->next.reserve(m + 2);
    this->null.reserve(m + 2);

    TElement el;
    for(int i = 0; i <= m; i++) {
        this->elems.push_back(el);
        this->next.push_back(0);
        this->null.push_back(true);
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
    if(this->null[hash] == true) {
        this->elems[hash] = el;
        this->null[hash] = false;
        this->size++;
        return;
    }
    
    //We must find another free slot to put the elment
    while(this->next[hash] != 0)
        hash = this->next[hash];

    //Assign it
    this->next[hash] = this->nextFree;
    this->elems[ this->nextFree ] = el;
    this->null[ this->nextFree ] = false;

    //Increase the number of elements that are in the container
    this->size++;

    //Assign a new free element
    this->assignNextFree();
}

template<class TElement>
bool HashMap<TElement>::remove(TElement el) {

    //Do the hashing (to get the index for the array)
    int hash = this->hash(el);

    if(this->null[hash])
        return false;

    //If the element that we are currently searching is the first and there is nobody chaining after him
    if(this->elems[hash] == el && this->next[hash] == 0) {
        this->null[hash] = true;
        this->nextFree = max(this->nextFree, hash);
        return true;
    }

    //Find the element we are searching for
    while(this->elems[hash] != el) {
        if( this->next[hash] == 0)
            return false;

        hash = this->next[hash];
    }

    //And move all chained elements one step before
    int prevHash = hash;
    while(this->next[hash] != 0) {
        this->elems[hash] = this->elems[ this->next[hash] ];
        prevHash = hash;
        hash = this->next[hash];
    }

    //Free the final element
    this->null[hash] = true;
    this->next[hash] = 0;
    this->nextFree = max(this->nextFree, hash);

    this->next[prevHash] = 0;
    return true;
}
template<class TElement>
void HashMap<TElement>::assignNextFree() {
    while(this->nextFree >= 1 && this->null[nextFree] == false)
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
        if(this->null[hash] == false && this->elems[hash] == el)
            return hash;

        //Else go to the next one

        //If it doesn't exist
        if(this->next[hash] == 0)
            return -1;

        //If it exists
            hash = this->next[hash];

    }while(true);
}

template<class TElement>
int HashMap<TElement>::getSize() {
    return this->size;
}

template<class TElement>
int HashMap<TElement>::hash(int el) {
    return el % this->m;

}

template<class TElement>
int HashMap<TElement>::hash(Elem<string, int> el) {
    int ASCIISum = 0;
    for(int i = 0; i < el.key.size(); i++) {
        ASCIISum += (int) el.key[i];
    }

    return this->hash(ASCIISum);
}

template<class TElement>
int HashMap<TElement>::hash(Elem<int, int> el) {
    return el.key % this->m;
}

template<class TElement>
int HashMap<TElement>::getHashValue() {
    return this->m;
}

template<class TElement>
vector<bool> HashMap<TElement>::getNullElements() {
    return this->null;
}


template class HashMap<int>;
template class HashMap< Elem<string, int> >;
template class HashMap< Elem<int, int> >;
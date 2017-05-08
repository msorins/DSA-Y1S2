//
// Created by Sorin Sebastian Mircea on 30/04/2017.
//

#include "DA.h"
#include "../Elem.h"

#include <string>
#include <iostream>
using namespace std;

template<class TElement>
DA<TElement>::DA() {
    /*
     * DESCR: Default constructor. Initialisez a dynamic array with 100 elements
     */
    this->cap = 100;
    this->elems = new TElement[100];
    this->len = 0;
}

template<class TElement>
DA<TElement>::DA(int cap) {
    /*
     * DESCR: Creates a new empty dynamic array with initial capacity cap
     * PRE: cap is integer
     * POST: a new dynamic array was creates
     */
    if(this->cap < 0)
        throw("Capacity must be a positive number");

    this->cap = cap;
    this->elems = new TElement[cap];
    this->len = 0;
}

template<class TElement>
DA<TElement>::~DA() {
    /*
     * DESCR: Destroys the DA
     * PRE: DA is really a DA
     * POST: DA is destroyed
     */

    delete[] this->elems;
}

template<class TElement>
int DA<TElement>::size() {
    /*
     * DESCR: Returns the size (number of elements) from the DA
     * PRE: DA is really a DA
     * POST: size <- size of DA
     */
    return this->len;
}

template<class TElement>
TElement DA<TElement>::getElement(int pos) {
    /*
     * DESCR: return element from the position i
     * PRE: DA is really a DA, post is an integer & 1<= pos <= DA->len
     * POST: getElement <- found element
     */
    if(pos < 1 || pos > this->len)
        throw("Invalid index");

    return this->elems[pos];
}

template<class TElement>
void DA<TElement>::setElement(int pos, TElement el) {
    /*
     * DESCR: sets element EL on position POS
     * PRE: DA is really a DA, post is an integer & 1<= pos <= DA->len
     * POST: new DA WITH THE GIVEN ELEMENT
     */

    if(pos < 1 || pos > this->len)
        throw("Invalid index");

    this->elems[pos] = el;
}

template<class TElement>
void DA<TElement>::resize(int newCap) {
    /*
     * DESCR: resizes the capacity
     * PRE: DA is really a DA, newCap is an integer & 1 <= newCap & newCap > this->len
     * POST: new DA with new capacity created
     */
    if(newCap < 1 || newCap < this->len)
        throw("Invalid value for capacity");

    //Generate a new list
    TElement* newList = new TElement[newCap + 1];

    //Copy current elements to that list
    for(int i = 1; i <= this->len; i++)
        newList[i] = this->elems[i];

    //Dealocate old list
    delete []this->elems;

    //Assign the new list
    this->elems = newList;

    //Assign the new cap
    this->cap = newCap;
}

template<class TElement>
void DA<TElement>::addToEnd(TElement el) {
    /*
     * DESCR: adds an element to the end of a DynamicArray. If the array is full, its capacity will be increased
     * PRE: DA is really a DA, el is really a TElement
     * POST: givent EL is added to the DA
     */

    //Check if array is not full
    if(this->len >= this->cap)
        this->resize( this->cap * 2);

    //Add that element to the back of array
    this->elems[ ++this->len ] = el;
}

template<class TElement>
void DA<TElement>::addToPosition(int pos, TElement el) {
    /*
     * DESC:  adds an element to a given position in the DynamicArray. If the array is full, its capacity will be increased
     * PRE: DA is really a DA, el is really a TElement, pos is an integer .. pos >= 1 && pos <= this->len
     * POST: New DA with that new element added
     */

    //Check if pos is valid
    if(pos < 1 || pos > this->len)
        throw("Invalid index");

    //Check if array is not full
    if(this->len + 1 == this->cap)
        this->resize( this->cap * 2);

    //Add the element to given position
    this->len++;
    for(int i = this->len ; i > pos; i--) {
        this->elems[i] = this->elems[i-1];
    }

    this->elems[pos] = el;
}

template<class TElement>
TElement DA<TElement>::deleteFromEnd() {
    /*
     * DESC: DELETS an element from the end of the DynamicArray. Returns the deleted element
     * PRE: DA is really DA, there are elements in DA
     * POST: Element is deletet and returned
     */
    if( this->len == 0 )
        throw("Cannot delete anymore");

    this->len--;
    return this->elems[ this->len + 1];
}

template<class TElement>
TElement DA<TElement>::deleteFromPosition(int pos) {
    /*
    * DESC: DELETS an element from the end of the DynamicArray. Returns the deleted element
    * PRE: DA is really DA, there are elements in DA. pos >= 1 && pos <= this->len
    * POST: Element is deletet and returned
    */
    if( this->len == 0 )
        throw("Cannot delete anymore");

    if( pos < 1 || pos > this->len)
        throw("Invalid deleting position");

    TElement res = this->elems[pos];

    for(int i = pos; i<= this->len; i++)
        this->elems[i] = this->elems[i+1];

    this->len--;
    return res;
}


template class DA<int>;
template class DA<string>;
template class DA< Elem< string > >;
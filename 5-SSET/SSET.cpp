//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#include "SSET.h"

template<class TElement>
DA<TElement> SSET<TElement>::getElems(){
    return elems;
}

template<class TElement>
void SSET<TElement>::setElems(DA<TElement> &elems) {
    SSET::elems = elems;
}

template<class TElement>
SSET<TElement>::SSET(int (*cmp)(TElement, TElement)) {
    this->comp = cmp;
}

template<class TElement>
bool SSET<TElement>::add(TElement el) {

    //Check if element is already in the SSET. If it is return false
    if(this->find(el))
        return false;

    for(int i = 1; i <= this->elems.size(); i++) {
        if(this->comp(el, this->elems.getElement(i))) {
            this->elems.addToPosition(i, el);
            return true;
        }
    }

    this->elems.addToEnd(el);
    return true;

}

template<class TElement>
bool SSET<TElement>::remove(TElement el) {
    //Check if element is NOT in the SSET. If it is return false
    if(this->find(el))
        return false;

    for(int i = 1; i <= this->elems.size(); i++) {
        if(this->elems.getElement(i) == el) {
            this->elems.deleteFromPosition(i);
            return true;
        }
    }

    return true;
}

template<class TElement>
bool SSET<TElement>::find(TElement el) {
    for(int i = 1; i <= this->elems.size(); i++)
        if(this->elems.getElement(i) == el)
            return true;

    return false;
}

template<class TElement>
int SSET<TElement>::size() {
    return this->elems.size();
}

template class SSET<int>;
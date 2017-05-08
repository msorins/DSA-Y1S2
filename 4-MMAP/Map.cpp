//
// Created by Sorin Sebastian Mircea on 07/05/2017.
//

#include "Map.h"
#include "DA/DA.h"

template<class TElement>
Map<TElement>::Map() {

}

template<class TElement>
Map<TElement>::~Map() {

}

template<class TElement>
void Map<TElement>::add(string key, TElement value) {
    /*
     * DESCR: add a new element with the given key to the map
     * PRE: key valid key, value valid value, Map valid map
     * POST: new Map with key introduced
     */

    //First try and search for existing key
    for(int i = 1; i <= this->elems.size(); i++) {
        if(this->elems.getElement(i).key == key) {

            //Add a new value to that key
            Elem<TElement> newEl = elems.getElement(i);
            newEl.vl.addToEnd(value);

            // Update that value
            this->elems.setElement(i, newEl);
            return;
        }

    }

    //Otherwise add it
    Elem<TElement> newEl;
    newEl.key=key;
    newEl.vl.addToEnd(value);

    this->elems.addToEnd(newEl);
}

template<class TElement>
bool Map<TElement>::remove(string key, TElement value) {

    //Iterate through the keys
    for(int i = 1; i <= this->elems.size(); i++) {

        //If i found the matching key
        if(this->elems.getElement(i).key == key) {

            for(int j = 1; j <= this->elems.getElement(i).vl.size(); j++) {
                //I found the matching element
                if( this->elems.getElement(i).vl.getElement(j) == value ) {

                    Elem<TElement> newI = this->elems.getElement(i);
                    newI.vl.deleteFromPosition(j);
                    this->elems.setElement(i, newI);

                    return true;
                }

            }

            return false;
        }

    }

    return false;
}

template<class TElement>
bool Map<TElement>::search(string key, TElement value) {
    //Iterate through the keys
    for(int i = 1; i <= this->elems.size(); i++) {

        //If i found the matching key
        if(this->elems.getElement(i).key == key) {

            for(int j = 1; j <= this->elems.getElement(i).vl.size(); j++) {
                //I found the matching element
                if( this->elems.getElement(i).vl.getElement(j) == value ) {
                    return true;
                }

            }

            return false;
        }

    }

    return false;
}

template<class TElement>
int Map<TElement>::size() {
    int crtSize = 0;
    for(int i = 1; i <= this->elems.size(); i++) {
        crtSize += this->elems.getElement(i).vl.size();
    }

    return crtSize;
}

template<class TElement>
DA<Elem<TElement>> Map<TElement>::getElems() {
    return elems;
}


template class Map<string>;

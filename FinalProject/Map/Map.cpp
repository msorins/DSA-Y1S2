//
// Created by Sorin Sebastian Mircea on 07/05/2017.
//

/*
#include "Map.h"
#include "../DA/DA.h"

template<class TElement>
Map<TElement>::Map() {

}

template<class TElement>
Map<TElement>::~Map() {

}

template<class TElement>
void Map<TElement>::add(string key, TElement value) {
    /*
     * DESCR: insert a new element with the given key to the map
     * PRE: key valid key, value valid value, Map valid map
     * POST: new Map with key introduced
     */

    //Check if key is already in the map


    //Otherwise insert it
/*
    Elem<TElement> newEl;
    newEl.key = key;
    newEl.el = value;

    this->elems.addToEnd(newEl);
}

template<class TElement>
bool Map<TElement>::remove(string key) {

    //Iterate through the keys
    for(int i = 1; i <= this->elems.size(); i++) {

        //If i found the matching key
        if(this->elems.getElement(i).key == key) {

            this->elems.deleteFromPosition(i);
            return true;
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
            if(this->elems.getElement(i).el == value)
                return true;
            return false;
        }

    }

    return false;
}

template<class TElement>
int Map<TElement>::size() {
    return this->elems.size();
}

template<class TElement>
DA<Elem<TElement>> Map<TElement>::getElems() {
    return elems;
}


template class Map<string>;
*/
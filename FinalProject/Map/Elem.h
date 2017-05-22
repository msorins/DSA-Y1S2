//
// Created by Sorin Sebastian Mircea on 07/05/2017.
//

#ifndef DSA_4MAP_TELEM_H
#define DSA_4MAP_TELEM_H
#include <string.h>
#include <iostream>
#include <list>

using namespace std;

template<class TElement>
class Elem {
public:
    string key;
    TElement el;

public:
    //Constructor
    Elem(string key="", TElement el=NULL);

    //Overload operators
    friend bool operator== (const Elem<TElement> &a, const Elem<TElement> &b) {
        return a.key == b.key;
    };

    friend bool operator!= (const Elem<TElement> &a, const Elem<TElement> &b) {
        return a.key != b.key;
    };
};



#endif //DSA_4MAP_TELEM_H

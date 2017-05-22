//
// Created by Sorin Sebastian Mircea on 07/05/2017.
//

#ifndef DSA_4MAP_TELEM_H
#define DSA_4MAP_TELEM_H
#include <string.h>
#include <iostream>
#include <list>

using namespace std;

template<class TKey, class TElement>
class Elem {
public:
    TKey key;
    TElement el;

public:
    //Constructor
    Elem();
    Elem(TKey key, TElement el);

    //Overload operators
    friend bool operator== (const Elem<TKey, TElement> &a, const Elem<TKey, TElement> &b) {
        return a.key == b.key;
    };

    friend bool operator!= (const Elem<TKey, TElement> &a, const Elem<TKey, TElement> &b) {
        return a.key != b.key;
    };
};



#endif //DSA_4MAP_TELEM_H

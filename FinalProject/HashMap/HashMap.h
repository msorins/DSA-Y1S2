//
// Created by Sorin Sebastian Mircea on 19/05/2017.
//

#ifndef DSA_4MAP_HASHMAP_H
#define DSA_4MAP_HASHMAP_H

#include <vector>
#include <string>
#include <iostream>
#include "../Map/Elem.h"

using namespace std;
#define EMPTY 0

template<class TElement>
class HashMap {
private:
    vector<TElement> elems;
    vector<int> next;
    vector<bool> null;
    int m;
    int size;
    int nextFree;
public:
    //Constructor
    HashMap(int m);

    //Setters and Getters
    int getSize();
    vector<TElement> getElems();
    vector<int> getNexts();

    //Functionality
    int hash(TElement el);


    void assignNextFree();
    void insert(TElement el);
    bool remove(TElement el);
    bool find(TElement el);
    int findPos(TElement el);


    //Overloading operators
    friend ostream &operator<<( ostream &output,
                                HashMap &hmapObj ) {
        /*
         * OUTPUTS THE OBJECT
         */;
        for(int i = 0; i < hmapObj.m ; i++) {
            output<<"( "<< to_string(hmapObj.elems[i])<<"-"<<to_string(hmapObj.next[i])<<" )\n";
        }

        return output;
    }

};



#endif //DSA_4MAP_HASHMAP_H

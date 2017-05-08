//
// Created by Sorin Sebastian Mircea on 07/05/2017.
//

#ifndef DSA_4MAP_MAP_H
#define DSA_4MAP_MAP_H


#include "DA/DA.h"
#include "Elem.h"

template<class TElement>
class Map {
private:
    DA< Elem<TElement> > elems;
public:
    //Constructor end destructor
    Map();
    ~Map();

    //Functionality
    void add(string key, TElement value);

    DA<Elem<TElement>> getElems();

    bool remove(string key, TElement value);
    bool search(string key, TElement value);
    int size();

    friend ostream &operator<<( ostream &output,
                                Map &mapObj ) {
        /*
         * OUTPUTS THE OBJECT
         */
        //output<<"Daaa"<<mapObj.e\;
        for(int i = 1; i <= mapObj.elems.size(); i++) {
            for(int j = 1; j <= mapObj.elems.getElement(i).vl.size(); j++) {
                output<<"key: "<<mapObj.elems.getElement(i).key<<" .Value: "<<mapObj.elems.getElement(i).vl.getElement(j)<<"\n";
            }
        }

        return output;
    }

};


#endif //DSA_4MAP_MAP_H

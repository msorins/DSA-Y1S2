//
// Created by Sorin Sebastian Mircea on 01/05/2017.
//

#ifndef INC_3_DLL_VECTOR_DLL_H
#define INC_3_DLL_VECTOR_DLL_H

#include "DLLNode.h"
#include <algorithm>
#include <vector>
#include "DA/DA.h"
using namespace std;

template<class TElement>
class DLL {
private:
    DA< DLLNode<TElement> > nodes;
    int head;
    int tail;
    int firstEmpty;

public:
    //Constructor
    DLL();

    //Getters and Setters
    int getHead() const;
    void setHead(int head);
    int getTail() const;
    void setTail(int tail);
    int getFirstEmpty() const;
    void setFirstEmpty(int firstEmpty);

    //Functionality
    int allocate();
    void deallocate(int pos);

    void insertFirst(TElement el);
    void insertAtPosition(int pos, TElement el);
    TElement deleteFirst();
    TElement deleteByValue(TElement el);
    TElement deleteByPosition(int pos);
    DLLNode<TElement> search(TElement el);


    friend ostream &operator<<( ostream &output,
                                DLL &dllObj ) {
        /*
         * OUTPUTS THE OBJECT
         */
        int crtPos = dllObj.head;

        while(crtPos != -1) {
            output << dllObj.nodes.getElement(crtPos).getInfo()<<" ";
            crtPos = dllObj.nodes.getElement(crtPos).getNext();

        }
        return output;
    }

};




#endif //INC_3_DLL_VECTOR_DLL_H

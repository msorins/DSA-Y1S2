//
// Created by Sorin Sebastian Mircea on 30/04/2017.
//

#ifndef INC_1_SINGLYLINKEDLISTDYNAMIC_SLL_H
#define INC_1_SINGLYLINKEDLISTDYNAMIC_SLL_H

template<class TElement>
class DA {
private:
    int cap; //maximum elements
    int len; //current number of elements
    TElement* elems;
public:

    //CONSTRUCTORS
    DA();
    DA(int cap);

    //DESTRUCTOR
    ~DA();

    //FUNCTIONALITY
    int size();
    TElement getElement(int pos);
    void setElement(int pos, TElement el);
    void addToEnd(TElement el);
    void addToPosition(int pos, TElement el);
    TElement deleteFromEnd();
    TElement deleteFromPosition(int pos);


    DA(const DA &A) { //Copy

        TElement* newElems = new TElement[A.cap];
        for(int i = 1; i<= A.len; i++)
            newElems[i] = A.elems[i];

        this->elems = newElems;
        this->len = A.len;
        this->cap = A.cap;
    }


    DA& operator = (DA A ) {
        TElement* newElems = new TElement[A.cap];
        for(int i = 1; i<= A.len; i++)
            newElems[i] = A.elems[i];

        this->elems = newElems;
        this->len = A.len;
        this->cap = A.cap;
        return *this;
    }


private:
    void resize(int newCap);

};




#endif //INC_1_SINGLYLINKEDLISTDYNAMIC_SLL_H

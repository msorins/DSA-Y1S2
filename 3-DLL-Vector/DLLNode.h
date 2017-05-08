//
// Created by Sorin Sebastian Mircea on 01/05/2017.
//

#ifndef INC_3_DLL_VECTOR_DLLNODE_H
#define INC_3_DLL_VECTOR_DLLNODE_H

template<class TElement>
class DLLNode {
private:
    TElement info;
    int next;
    int prev;

public:
    //Constructor
    DLLNode();
    DLLNode(TElement info, int prev, int next) : info(info), prev(prev), next(next) {}

    //Setters and Getters
    void setInfo(TElement info);
    void setNext(int next);
    void setPrev(int prev);
    TElement getInfo() const;
    int getNext() const;
    int getPrev() const;


};

#endif //INC_3_DLL_VECTOR_DLLNODE_H

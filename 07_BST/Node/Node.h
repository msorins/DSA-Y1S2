//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#ifndef INC_07_BST_NODE_H
#define INC_07_BST_NODE_H
#include <iostream>
using namespace std;

template<class TElement>
class Node {
public:
    TElement info;
    Node *left;
    Node *right;

public:

    //Constructors
    Node();
    Node(TElement info);

};



#endif //INC_07_BST_NODE_H

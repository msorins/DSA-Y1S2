//
// Created by Sorin Sebastian Mircea on 09/06/2017.
//

#ifndef INC_6_BINARYTREE_NODE_H
#define INC_6_BINARYTREE_NODE_H

template<class TElement>
class Node {
public:
    TElement info;
    Node *father, *st, *dr;
};


#endif //INC_6_BINARYTREE_NODE_H

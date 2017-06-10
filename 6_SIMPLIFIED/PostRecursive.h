//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#ifndef INC_6_SIMPLIFIED_POSTRECURSIVE_H
#define INC_6_SIMPLIFIED_POSTRECURSIVE_H
#include <iostream>
using namespace std;

class PostRecursive {
private:
    int *v;
    int n;
public:
    PostRecursive(int *v, int n);
    void compute(int pos);
};



#endif //INC_6_SIMPLIFIED_POSTRECURSIVE_H

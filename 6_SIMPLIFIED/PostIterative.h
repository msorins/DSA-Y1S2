//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#ifndef INC_6_SIMPLIFIED_POSTITERATIVE_H
#define INC_6_SIMPLIFIED_POSTITERATIVE_H

#include <iostream>
#include <stack>
using namespace std;

class PostIterative {
private:
    int *v;
    int n;
public:
    PostIterative(int *v, int n);
    void compute(int pos);
};



#endif //INC_6_SIMPLIFIED_POSTITERATIVE_H

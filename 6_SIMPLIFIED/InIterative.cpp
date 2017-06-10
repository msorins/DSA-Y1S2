//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#include "InIterative.h"

InIterative::InIterative(int *v, int n) {
    this->v = v;
    this->n = n;
    this->compute(1);
}

void InIterative::compute(int pos) {
    stack<int> st;

    while(pos <= this->n) {
        st.push(pos);
        pos *= 2;
    }

    while(!st.empty()) {
        pos = st.top(); st.pop();
        cout << pos << " ";

        if(pos * 2 + 1 > this->n) continue;
        pos = pos * 2 + 1;

        while(pos <= this->n) {
            st.push(pos);
            pos *= 2;
        }

    }
}

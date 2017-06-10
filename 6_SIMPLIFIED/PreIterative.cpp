//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#include "PreIterative.h"

PreIterative::PreIterative(int *v, int n) {
    this->v = v;
    this->n = n;
    this->compute(1);
}

void PreIterative::compute(int pos) {
    stack<int> st;
    st.push(pos);
    while(!st.empty()) {
        pos = st.top(); st.pop();
        cout << pos << " ";
        if(pos * 2 + 1 <= this->n)
            st.push(pos * 2 + 1);

        if(pos * 2 <= this->n)
            st.push(pos * 2);
    }
}

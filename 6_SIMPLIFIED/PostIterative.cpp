//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#include "PostIterative.h"

PostIterative::PostIterative(int *v, int n) {
    this->v = v;
    this->n = n;
    this->compute(1);
}

void PostIterative::compute(int pos) {
    stack<int> st;

    while(pos <= this->n) {
        //RIGHT
        if(pos * 2 + 1 <= this->n)
            st.push(pos * 2 + 1);

        st.push(pos);
        //LEFT
        pos = pos * 2;
    }

    while(!st.empty()) {
        pos = st.top(); st.pop();
        if(pos * 2 + 1 <= this->n && !st.empty() && pos * 2 + 1 == st.top()) {
            st.pop();
            st.push(pos);
            pos = pos * 2 + 1;
        } else {
            cout << pos <<" ";
            continue;
        }

        while(pos <= this->n) {
            if(pos * 2 + 1 <= this->n)
                st.push(pos * 2 + 1);

            st.push(pos);
            pos = pos * 2;
        }

    }
}

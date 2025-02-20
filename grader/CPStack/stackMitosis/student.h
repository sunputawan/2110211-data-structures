#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b) {
    CP::stack<T> tmp;
    CP::stack<T> toDuplicate;
    int cnt = 0;
    while(cnt!=a) {
        //std::cout<<cnt<<'\n';
        tmp.push(top());
        pop();
        cnt++;
    }
    while(cnt!=b+1) {
        toDuplicate.push(top());
        pop();
        cnt++;
    }
    while(!toDuplicate.empty()) {
        push(toDuplicate.top());
        push(toDuplicate.top());
        toDuplicate.pop();
    }
    while(!tmp.empty()) {
        push(tmp.top());
        tmp.pop();
    }
}

#endif
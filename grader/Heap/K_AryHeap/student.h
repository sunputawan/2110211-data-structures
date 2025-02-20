#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>

#define K 4

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
    T tmp = mData[idx];
    while (idx > 0) {
        size_t p = (idx - 1) / K;
        if ( mLess(tmp,mData[p]) ) break;
        mData[idx] = mData[p];
        idx = p;
    }
    mData[idx] = tmp;
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    T tmp = mData[idx];
    size_t c;
    while ((c = K * idx + 1) < mSize) {
        int ans = c;
        for(int i=1;i<K;i++) {
            if (c + i < mSize && mLess(mData[ans],mData[c + i]) ) ans = c+i;

        }
        if ( mLess(mData[ans],tmp) ) break;
        mData[idx] = mData[ans];
        idx = ans;
    }
    mData[idx] = tmp;
}

#endif


#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once
#include <vector>
#include <queue>
#include "queue.h"

template <typename T>
std::vector< CP::queue<T> > CP::queue<T>::split_queue(int k) {
    std::vector<CP::queue<T> > qs(k);
    // code here
    for(int i=0;i<mSize;i++) {
        qs[i%k].push(mData[(mFront+i)%mCap]);
    }
    delete [] mData;
    mData = new T[1];
    mFront = 0;
    mSize = 0;
    return qs;
}

#endif


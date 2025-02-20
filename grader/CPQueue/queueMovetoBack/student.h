#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  T tmp = mData[(mFront + pos)% mCap];
  int idx = (mFront+pos)%mCap;
  int count = mSize-1-pos;
  while(count--) {
    mData[idx] = mData[(idx+1)%mCap];
    idx = (idx+1)%mCap;
  }
  mData[idx] = tmp;
}

#endif

#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  // Your code here
  aux = (aux == 0) ? 1 : 0;
}

template <typename T>
const T& CP::queue<T>::front() const {
  // You MAY need to edit this function
  return mData[(aux == 0) ? mFront : (mFront + mSize - 1) % mCap];
}

template <typename T>
const T& CP::queue<T>::back() const {
  // You MAY need to edit this function
  return mData[(aux == 0) ? (mFront + mSize - 1) % mCap : mFront];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  // You MAY need to edit this function
  ensureCapacity(mSize + 1);
  if(aux == 0) {
    mData[(mFront + mSize) % mCap] = element;
  }
  else {
    mFront = (mFront - 1 + mCap) % mCap;
    mData[mFront] = element;
  }
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  // You MAY need to edit this function
  if(aux == 0) {
    mFront = (mFront + 1) % mCap;
  }
  mSize--;
}

#endif
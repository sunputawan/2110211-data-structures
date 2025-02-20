#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  //your code here
  int size = b-a+1;
  for(int i=0;i<size/2;i++) {
    //std::cout<<"log : "<<a<<' '<<i<<"   "<<a+i<<' '<<a+size-i-1<<'\n';
    T tmp = mData[(mFront + a + i) % mCap];
    mData[(mFront + a + i) % mCap] = mData[(mFront + a + size - i - 1) % mCap];
    mData[(mFront + a + size - i - 1) % mCap] = tmp;
  }
}

#endif

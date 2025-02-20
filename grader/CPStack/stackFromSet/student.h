#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  CP::stack<T> tmp;
  while(first!=last) {
    tmp.push(*first);
    //std::cout<<*first<<'\n';
    first++;
  }
  mData = new T[1]();
  mSize = 0;
  mCap = 1;
  int cnt = tmp.size();
  while(cnt--) {
    push(tmp.top());
    tmp.pop();
  }
  // for(size_t i=0;i<mSize;i++) {
  //   std::cout<<mData[i]<<' ';
  // }
  //std::cout<<'\n';
}

#endif

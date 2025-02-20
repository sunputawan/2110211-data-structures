#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  //your code here
  //should return something
  std::vector<std::vector<T>> v;
  std::vector<T> tmp;
  std::vector<T> ref;
  for(int i=mSize-1;i>=0;i--) {
    ref.push_back(mData[i]);
    // std::cout<<mData[i]<<' ';
  }
  // std::cout<<'\n';
  size_t idx = 0;
  for(size_t cnt=0;cnt<k;cnt++) {
    size_t i = idx;
    while(i<mSize) {
      tmp.push_back(ref[i]);
      // std::cout<<i<<' '<<ref[i]<<'\n';
      i+=k;
    }
    std::reverse(tmp.begin(),tmp.end());
    v.push_back(tmp);
    tmp.clear();
    idx++;
  }

  return v;
}

#endif


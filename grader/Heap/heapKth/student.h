#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"


int min(int a,int b) {
  return (a<b) ? a:b;
}
template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> v;
  for(int i=0;i<=min(mSize-1,14);i++) {
    v.push_back(mData[i]);
  }
  sort(v.begin(), v.end(), mLess);
  reverse(v.begin(), v.end());

  return v[k-1];
}

#endif

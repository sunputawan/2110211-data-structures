#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"
#include <algorithm>

int max(int a, int b) {
  return (a>b) ? a:b;
}

int min(int a, int b) {
  return (a<b) ? a:b;
}
template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> r;
  int idx = 1;
  while(k--) {
    idx *= 2;
    if(idx - 1 >= mSize) return r;
  }
  idx -= 1;
  for(int i=idx; i<min(idx*2+1,mSize); i++) {
    r.push_back(mData[i]);
  }
  sort(r.begin(),r.end(),mLess);
  reverse(r.begin(),r.end());
  return r;
}


#endif


#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include <vector>

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  // Write code here
  std::vector<int> e(mSize+1);
  std::vector<T> tmp;
  for(auto x: ranges) {
    e[x.first-mData] += 1;
    e[x.second-mData] -= 1;
  }
  for(int i=1;i<mSize;i++) {
    e[i] += e[i-1];
  }

  for(int i=0;i<mSize;i++) {
    if(!e[i]) {
      tmp.push_back(mData[i]);
    }
  }

  mSize = 0;
  for(T &x:tmp) {
    mData[mSize++] = x;
  }

  return;
}

#endif

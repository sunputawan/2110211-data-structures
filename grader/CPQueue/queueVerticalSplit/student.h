#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const
{
  // your code here
  output.resize(k);
  int size = mSize/k;
  int mod = mSize%k;
  int idx = 0;
  for(int i=0;i<k;i++) {
    int cnt = size + ((mod-- > 0) ? 1:0);
    while(cnt--) {
      output[i].push(mData[(mFront + idx++) % mCap]);
    }
  }
}

#endif

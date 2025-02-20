#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"
#include <queue>

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  // Your code here
  std::queue<size_t> q;
  q.push(0);
  while(!q.empty()) {
    size_t idx = q.front(); q.pop();
    if(idx*2+1 < mSize) {
      if(mLess(mData[idx*2+1], mData[idx])) {
        q.push(idx*2+1);
      }
      else return false;
    }
    if(idx*2+2 < mSize) {
      if(mLess(mData[idx*2+2], mData[idx])) {
        q.push(idx*2+2);
      }
      else return false;
    }

  }
  // Return something
  return true;
}

#endif
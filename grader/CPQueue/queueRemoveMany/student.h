#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>
#include <set>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  sort(pos.begin(),pos.end());
  std::vector<T> tmp;
  std::set<size_t> s;
  for(size_t x:pos) {
    s.insert(x);
  }
  for(size_t i=0;i<mSize;i++) {
    if(s.find(i) == s.end()) {
      tmp.push_back(mData[(mFront+i)%mCap]);
    }
  }
  delete [] mData;
  mData = new T[tmp.size()]();
  mFront = 0;
  mSize = 0;
  mCap = tmp.size();
  for(T &x:tmp) {
    push(x);
  }

}

#endif

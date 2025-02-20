#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  // Write code here
  output.resize(k);
  int size = mSize / k;
  int mod = mSize % k;
  int idx = mSize - 1;
  for(int i=0;i<k;i++) {
    std::stack<T> tmp;
    int count = size + ((mod-- > 0) ? 1 : 0);
    while(count--) {
      tmp.push(mData[idx--]);
    }
    while(!tmp.empty()) {
      output[i].push(tmp.top());
      tmp.pop();
    }
  }
}

#endif

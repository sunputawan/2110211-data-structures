#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  //your code here
  std::vector<int>::iterator it = std::upper_bound(aux.begin(),aux.end(),idx);
  it--;
  //std::cout<<*it<<' '<<idx-*it<<'\n';
  return mData[it-aux.begin()][idx-*it];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  //your code here
  //you MAY need this function
  aux.push_back(mSize);
}

#endif

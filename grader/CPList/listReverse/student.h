#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  //write your code here
  if(mSize == 0 || a == b) {
    return a;
  }
  std::vector<T> tmp;
  CP::list<T>::iterator it = a;
  while(it != b) {
    tmp.push_back(it.ptr -> data);
    it++;
  }
  std::reverse(tmp.begin(),tmp.end());
  // for(auto x:tmp) {
  //   std::cout<<x<<' ';
  // }
  // std::cout<<'\n';
  it = a;
  for(auto x:tmp) {
    it.ptr -> data = x;
    it++;
  }
  return a;
}

#endif

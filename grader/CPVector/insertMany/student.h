#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <map>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  std::map<int,T> mp;
  for(size_t i=0;i<data.size();i++) {
    mp[data[i].first] = data[i].second;
  }
  T *tmp = mData;
  size_t oldSize = mSize;
  mData = new T[1]();
  mSize = 0;
  mCap = 1;
  size_t i = 0;
  for(auto x:mp) {
    while(i<x.first) {
      push_back(tmp[i]);
      i++;
    }
    push_back(x.second);
  }
  while(i<oldSize) {
    push_back(tmp[i]);
    i++;
  }
  delete [] tmp;
}

#endif

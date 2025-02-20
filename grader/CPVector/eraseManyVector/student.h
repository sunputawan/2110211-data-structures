#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  std::map<int,T> mp;
  for(size_t i=0;i<mSize;i++) {
    mp[i] = mData[i];
  }
  for(auto x:pos) {
    if(mp.find(x) != mp.end()) {
      mp.erase(x);
    }
  }
  delete [] mData;
  mData = new T[1]();
  mSize = 0;
  mCap = 1;

  for(auto x:mp) {
    push_back(x.second);
  }
}

#endif

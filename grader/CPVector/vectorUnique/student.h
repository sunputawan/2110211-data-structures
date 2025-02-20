#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include <map>

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  CP::vector<T> v;
  std::map<T,int> mp;
  std::map<int,T> ans;
  for(size_t i=0;i<mSize;i++) {
    if(mp.find(mData[i]) == mp.end()) mp[mData[i]] = i;
  }

  for(auto x:mp) {
    ans[x.second] = x.first;
  }
  delete [] mData;
  mData = new T[1](); mSize = 0; mCap = 1;
  for(auto x:ans) {
    //std::cout<<x.first<<' '<<x.second<<'\n';
    push_back(x.second);
  }
}

#endif

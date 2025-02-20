#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  //your code here
  sort(pos.begin(),pos.end());
  std::vector<T> ans;
  size_t posIdx = 0;
  for(size_t i=0;i<mSize;i++) {
    while(posIdx != pos.size() && pos[posIdx] < i) {
      posIdx++;
    }
    if(posIdx != pos.size() && pos[posIdx] == i) {
      ans.push_back(mData[(mFront+i)%mCap]);
      posIdx++;
    }
  }
  //should return something
  sort(ans.begin(),ans.end(),comp);
  // for(auto x:ans) {
  //   std::cout<<x<<' ';
  // }
  // std::cout<<'\n';
  return ans[0];
}

#endif

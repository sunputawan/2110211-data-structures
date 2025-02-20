#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  CP::vector<T> v;
  for(auto it = first; it < last; it++) {
    v.push_back(*it);
  }
  size_t f = first-begin();
  size_t l = last-begin();
  for(int i=f;i<l-k;i++) {
    mData[i] =  v[i-f+k];
  }
  for(int i=l-k;i<l;i++) {
    mData[i] = v[i-l+k];
  }
  
}

#endif

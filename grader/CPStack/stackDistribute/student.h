#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here
  std::vector<std::vector<T>> v;
  std::vector<T> tmp;
  size_t sz = mSize/k;
  size_t mod = mSize%k;
  size_t idx = mSize-1;
  for(size_t i=0;i<k;i++) {
    tmp.clear();
    for(size_t j=0;j<sz;j++) {
      tmp.push_back(mData[idx--]);
    }
    if(mod != 0){
      tmp.push_back(mData[idx--]);
      mod--;
    }
    v.push_back(tmp);
  }

  return v;
}
#endif

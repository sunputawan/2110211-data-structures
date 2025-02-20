#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {

  //write your code here
  CP::priority_queue<T,Comp> tmp1 = other, tmp2;
  tmp2.mSize = mSize;
  tmp2.mCap = mCap;
  tmp2.mData = new T[mCap];
  tmp2.mLess = mLess;
  if(tmp1.mSize != tmp2.mSize) {
    return false;
  }
  for(size_t i=0; i<mSize; i++) {
    tmp2.mData[i] = mData[i];
  }

  while(!tmp1.empty() && !tmp2.empty()) {
    if(tmp1.top() != tmp2.top()) return false;
    tmp1.pop();
    tmp2.pop();
  }
  return true; // you can change this line
}

#endif

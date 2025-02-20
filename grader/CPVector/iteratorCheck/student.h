#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::valid_iterator(CP::vector<T>::iterator it) const {
  //write your code here
  if(mSize == 0) return false;
  
  if(mData <= it && it < mData+mSize) return true;
  
  return false;
}

#endif

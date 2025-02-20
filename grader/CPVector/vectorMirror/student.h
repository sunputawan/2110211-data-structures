#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  T *newData = new T[mSize*2]();
  for(size_t i=0;i<mSize;i++) {
    newData[i] = mData[i];
  }
  for(size_t i=0;i<mSize;i++) {
    newData[i+mSize] = mData[mSize-1-i];
  }
  delete [] mData;
  mData = newData;
  mSize *=2;
  mCap = mSize;
}

#endif

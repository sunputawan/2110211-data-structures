#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  int pos = position - mData;
  ensureCapacity(mSize+(last-first));
  int size = last-first;
  //std::cout<<pos<<'\n';
  for(int i=mSize+size;i>=pos+size;i--) {
    mData[i] = mData[i-size];
  }
  for(int i=0;i<size;i++) {
    mData[i+pos] = *(first+i);
  }
  mSize += size;
}

#endif

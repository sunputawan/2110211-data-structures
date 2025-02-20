#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> result;
  if(it == begin()) {
    it.ptr->prev = result.mHeader;
    it.ptr->prev->next = it.ptr;
    mHeader->prev->next = result.mHeader;
    mHeader->prev->next->prev = mHeader->prev;

    mHeader->prev = mHeader;
    mHeader->next = mHeader;
    result.mSize = mSize;
    mSize = 0;
  }
  else if(it == end()) {

  }
  else {
    mHeader->prev->next = result.mHeader;
    mHeader->prev->next->prev = mHeader->prev;

    it.ptr->prev->next = mHeader;
    it.ptr->prev->next->prev = it.ptr->prev;


    it.ptr->prev = result.mHeader;
    it.ptr->prev->next = it.ptr;

    result.mSize = mSize-pos;
    mSize = pos;
    
  }

  return result;
}

#endif

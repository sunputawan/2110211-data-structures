#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  if(a-b > 0) {
    auto tmp = a;
    a = b;
    b = tmp;
  }
  if(a-mData < 0 || a+m-1-mData >= mSize) return false;
  if(b-mData < 0 || b+m-1-mData >= mSize) return false;
  if(a+m-1 >= b) return false;
  if(m <= 0) return false;

  size_t i = 0;
  auto aIt = a;
  auto bIt = b;
  while(i!=m) {
    T tmp = *(aIt+i);
    *(aIt+i) = *(bIt+i);
    *(bIt+i) = tmp;
    i++;
  }
  return true;
}

#endif

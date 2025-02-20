#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  size_t cnt = pos;
  CP::stack<T> tmp;
  while(cnt--) {
    tmp.push(top());
    pop();
  }
  push(value);
  while(!tmp.empty()) {
    push(tmp.top());
    tmp.pop();
  }
}

#endif

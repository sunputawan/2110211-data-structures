#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
  CP::stack<T> tmp1;
  CP::stack<T> tmp2;
  while(!s2.empty() && m--) {
    tmp1.push(s2.top());
    s2.pop();
  }
  while(!empty() && k--) {
    tmp2.push(top());
    pop();
  }
  while(!tmp1.empty()) {
    push(tmp1.top());
    tmp1.pop();
  }
  while(!tmp2.empty()) {
    push(tmp2.top());
    tmp2.pop();
  }
}
#endif

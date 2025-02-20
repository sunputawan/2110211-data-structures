#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>


template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  //write your code here
  int p = 0;
  int x = 1;
  while(x <= mSize) {
    p++;
    x *= 2;
  }
  return p-1;
}
#endif


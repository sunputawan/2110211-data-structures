#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  //write your code here
  auto it = a;
  int i=0;
  while(it!=b) {
    if(*it == value) {
      auto tmpNext = it.ptr -> next;
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      mSize--;
      delete it.ptr;
      it = tmpNext;

      node *newNode = new node();
      newNode->data = value;

      newNode->prev = output.mHeader;
      newNode->next = output.begin().ptr;
      newNode->prev->next = newNode;
      newNode->next->prev = newNode;
      output.mSize++;
      it = tmpNext;
    }
    else it++;
  }
  //std::cout<<"blalglabll\n";
}

#endif

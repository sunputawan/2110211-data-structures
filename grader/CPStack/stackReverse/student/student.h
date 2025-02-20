#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <queue>
#include <stack>

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
	// write your code here
	std::queue<T> q;
	std::stack<T> s;
	if(first > last) {
		return;
	}
	last = (last < mSize-1) ? last : mSize-1;
	last = (last >= 0) ? last : 0;
	first = (first < mSize-1) ? first : mSize-1;
	first = (first >= 0) ? first : 0;
	for(int i=0;i<first;i++) {
		s.push(top());
		pop();
	}
	for(int i=first;i<=last;i++) {
		q.push(top());
		pop();
	}

	while(!q.empty()) {
		push(q.front());
		q.pop();
	}

	while(!s.empty()) {
		push(s.top());
		s.pop();
	}
}

#endif

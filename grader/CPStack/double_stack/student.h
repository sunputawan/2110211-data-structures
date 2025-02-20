#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <stack>

template <typename T>
void CP::stack<T>::pop() {
	// modify method here
	if(stack_a.empty()) {
		size_t n = (stack_b.size()+1)/2;
		stack<T> tmpl,tmpr;
		while(!stack_b.empty()) {
			tmpl.push(stack_b.top());
			stack_b.pop();
		}
		while(n--) {
			tmpr.push(tmpl.top());
			tmpl.pop();
		}
		while(!tmpr.empty()) {
			stack_a.push(tmpr.top());
			tmpr.pop();
		}
		while(!tmpl.empty()) {
			stack_b.push(tmpl.top());
			tmpl.pop();
		}
	}
	stack_a.pop();
}

template <typename T>
const T& CP::stack<T>::top() {
	// modify method here
	if(stack_a.empty()) {
		size_t n = (stack_b.size()+1)/2;
		stack<T> tmpl,tmpr;
		while(!stack_b.empty()) {
			tmpl.push(stack_b.top());
			stack_b.pop();
		}
		while(n--) {
			tmpr.push(tmpl.top());
			tmpl.pop();
		}
		while(!tmpr.empty()) {
			stack_a.push(tmpr.top());
			tmpr.pop();
		}
		while(!tmpl.empty()) {
			stack_b.push(tmpl.top());
			tmpl.pop();
		}
	}
	return stack_a.top();
}

template <typename T>
const T& CP::stack<T>::bottom() {
	// write your code here
	if(stack_b.empty()) {
		size_t n = (stack_a.size()+1)/2;
		stack<T> tmpl,tmpr;
		while(!stack_a.empty()) {
			tmpr.push(stack_a.top());
			stack_a.pop();
		}
		while(n--) {
			tmpl.push(tmpr.top());
			tmpr.pop();
		}
		while(!tmpr.empty()) {
			stack_a.push(tmpr.top());
			tmpr.pop();
		}
		while(!tmpl.empty()) {
			stack_b.push(tmpl.top());
			tmpl.pop();
		}
	}
	return stack_b.top();
}

template <typename T>
void CP::stack<T>::push_bottom(const T& element) {
	// write your code here
	stack_b.push(element);
}

template <typename T>
void CP::stack<T>::pop_bottom() {
	// write your code here
	if(stack_b.empty()) {
		size_t n = (stack_a.size()+1)/2;
		stack<T> tmpl,tmpr;
		while(!stack_a.empty()) {
			tmpr.push(stack_a.top());
			stack_a.pop();
		}
		while(n--) {
			tmpl.push(tmpr.top());
			tmpr.pop();
		}
		while(!tmpr.empty()) {
			stack_a.push(tmpr.top());
			tmpr.pop();
		}
		while(!tmpl.empty()) {
			stack_b.push(tmpl.top());
			tmpl.pop();
		}
	}
	stack_b.pop();
}
#endif
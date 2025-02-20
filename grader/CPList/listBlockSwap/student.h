#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "list.h"

template <typename T>
void CP::list<T>::block_swap(iterator a1, iterator a2, iterator b1, iterator b2) {
	// write your code here
	if(a1 == a2 && b1 == b2) return;

	if(a1 == b2) {
		std::swap(a1,b1);
		std::swap(a2,b2);
	}

	if(a2 == b1) {
		iterator beforeA = a1.ptr->prev;
		iterator lastA = a2.ptr->prev;
		iterator beforeB = b1.ptr->prev;
		iterator lastB = b2.ptr->prev;

		//cut connection of [a1,a2)
		a1.ptr->prev->next = a2.ptr;
		a2.ptr->prev = a1.ptr->prev;

		//cut connection of [b1,b2)
		b1.ptr->prev->next = b2.ptr;
		b2.ptr->prev = b1.ptr->prev;

		//no node between a2 and b1 since a2 == b1
		//connect b to new position
		lastB.ptr->next = a1.ptr;
		a1.ptr->prev = lastB.ptr;

		//connect the node before a1
		beforeA.ptr->next = b1.ptr;
		b1.ptr->prev = beforeA.ptr;

		//connect the node after b2
		b2.ptr->prev = lastA.ptr;
		lastA.ptr->next = b2.ptr;
	}
	else {
		if(b1 == b2) {
			std::swap(a1,b1);
			std::swap(a2,b2);
		}

		iterator beforeA = a1.ptr->prev;
		iterator lastA = a2.ptr->prev;
		iterator beforeB = b1.ptr->prev;
		iterator lastB = b2.ptr->prev;

		//cut connection of [a1,a2)
		a1.ptr->prev->next = a2.ptr;
		a2.ptr->prev = a1.ptr->prev;

		//cut connection of [b1,b2)
		b1.ptr->prev->next = b2.ptr;
		b2.ptr->prev = b1.ptr->prev;

		//there exists node between a and b
		if(a1 == a2) {
			//a is empty put b in front of a
			beforeA.ptr->next = b1.ptr;
			b1.ptr->prev = beforeA.ptr;

			lastB.ptr->next = a1.ptr;
			a1.ptr->prev = lastB.ptr;
			return;
		}

		//connect node to beforeA
		beforeA.ptr->next = b1.ptr;
		b1.ptr->prev = beforeA.ptr;

		//connect node to beforeB
		beforeB.ptr->next = a1.ptr;
		a1.ptr->prev = beforeB.ptr;

		//connect node to a2
		a2.ptr->prev = lastB.ptr;
		lastB.ptr->next = a2.ptr;

		//connect node to b2
		b2.ptr->prev = lastA.ptr;
		lastA.ptr->next = b2.ptr;
	}
}

#endif

#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
    size_t thisRemaining = mCap - mSize;
    size_t otherRemaining = other.mCap - other.mSize;
    if(thisRemaining > otherRemaining) return 1;
    if(thisRemaining == otherRemaining) return 0;
    if(thisRemaining < otherRemaining) return -1;
}

#endif

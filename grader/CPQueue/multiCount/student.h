#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    //write your code here
    std::map<T,size_t> mp;
    for(int i=0;i<mSize;i++) {
        mp[mData[(mFront+i)%mCap]]++;
    }

    std::vector<std::pair<T,size_t>> v;
    for(T &x:k) {
        v.push_back({x,mp[x]});
    }

    return v;
}

#endif

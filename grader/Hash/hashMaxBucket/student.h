#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename KeyT,
          typename MappedT,
          typename HasherT,
          typename EqualT>
size_t CP::unordered_map<KeyT,MappedT,HasherT,EqualT>::max_bucket_length() {
    // your code here
    size_t max = mBuckets[0].size();
    for(auto &x:mBuckets) {
        if(max < x.size()) max = x.size();
    }
    return max;
}

#endif

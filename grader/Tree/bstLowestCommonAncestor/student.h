
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "map_bst.h"


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::recursive(node* n,CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    // You may need this function
    KeyT a = (*p).first, b = (*q).first, x = n -> data.first;
    if(mLess(a,x) && mLess(b,x)) return recursive(n -> left, p, q);
    if(mLess(x,a) && mLess(x,b)) return recursive(n -> right, p, q);
    return iterator(n);
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::lca(CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    // Write your code here
    return recursive(mRoot, p, q);
}

#endif

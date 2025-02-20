#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

//you can use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf(node* n) {
  if(n->left == NULL && n->right == NULL) return 0;
  else if(n->left == NULL) {
    return 1 + shallowest_leaf(n->right);
  }
  else if(n->right == NULL) {
    return 1+ shallowest_leaf(n->left);
  }
  else {
    return 1 + std::min(shallowest_leaf(n->left), shallowest_leaf(n->right));
  }

}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf() {
  //write your code here
  if(mSize == 0) {
    return -1;
  }
  return shallowest_leaf(mRoot);
}


#endif

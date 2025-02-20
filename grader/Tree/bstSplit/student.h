#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  node* p = mRoot;
  node* tmp = NULL;
  while(p != NULL) {
    int cmp = compare(p->data.first, val);
    if(cmp == 0) {
      tmp = p;
      break;
    }
    else if(cmp == -1) {
      p = p->right;
    }
    else {
      tmp = p;
      p = p->left;
    }
  }
  std::cout<<"tmp : "<<tmp->data.first<<'\n';
  if(tmp == NULL) return result;

  if(tmp -> parent == NULL) {
    result.mRoot = tmp;
    mRoot = NULL;
  }
  else {
    
    while(tmp -> parent != NULL) {
      if(tmp -> parent -> left == tmp) {
        tmp = tmp -> parent;
      }
      else break;
    }

    tmp -> parent -> right = tmp -> left;
    tmp -> left -> parent = tmp -> parent;
    tmp -> parent = NULL;
    tmp -> left = NULL;
    result.mRoot = tmp;
  }

  return result;
}

#endif

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

namespace CP {

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::node_relation(iterator it1, iterator it2) {
    // Write code here
    node *parent;
    node *a = find_node((*it1).first, mRoot, parent);
    node *b = find_node((*it2).first, mRoot, parent);
    //if(a == b) return 4;
    if(a->parent == b || b->parent == a) {
        return 1;
    }
    int ans = -1;
    int aLevel = 0, bLevel = 0;
    node *p = a;
    while(p != NULL) {
        aLevel++;
        if(p == b) ans = 2;
        p = p->parent;
    } aLevel--;
    p = b;
    while(p != NULL) {
        bLevel++;
        if(p == a) ans = 2;
        p = p->parent;
    } bLevel--;

    if(ans == 2) return 2;
    else if(aLevel == bLevel) return 4;
    else return 3;
}

}

#endif

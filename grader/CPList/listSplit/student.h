void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    int n = mSize;
    int k = (mSize-1)/2;
    auto it = begin();
    for(int i=0;i<=k;i++) {
        auto tmpNext = it.ptr->next;
        it.ptr->prev->next = it.ptr->next;
        it.ptr->next->prev = it.ptr->prev;
        mSize--;

        it.ptr->prev = list1.mHeader->prev;
        it.ptr->next = list1.mHeader;

        list1.mHeader->prev->next = it.ptr;
        list1.mHeader->prev = it.ptr;
        list1.mSize++;
        it = tmpNext;
    }

    for(int i=k+1;i<n;i++) {
        auto tmpNext = it.ptr->next;
        it.ptr->prev->next = it.ptr->next;
        it.ptr->next->prev = it.ptr->prev;
        mSize--;

        it.ptr->prev = list2.mHeader->prev;
        it.ptr->next = list2.mHeader;

        list2.mHeader->prev->next = it.ptr;
        list2.mHeader->prev = it.ptr;
        list2.mSize++;
        it = tmpNext;
    }

    return;

}

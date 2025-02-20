void shift(int k) {
	// TODO: Add your code here
	CP::list<T>::iterator it = begin();
	if(k>0){
		while(k--) {
			if(it == mHeader) {
				k++;
			}
			it++;
		}
		if(it == mHeader) {
			it++;
		}
	}
	else if(k<0) {
		k = -k;
		while(k--) {
			if(it == mHeader) {
				k++;
			}
			//std::cout<<*it<<' ';
			it--;
		}
		if(it == mHeader) {
			it--;
		}
	}
	//std::cout<<"\nHead : "<<*it<<'\n';

	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;
	delete mHeader;

	mHeader = new node(T(), it.ptr->prev, it.ptr);
	mHeader->prev->next = mHeader;
	mHeader->next->prev = mHeader;

	return;
}

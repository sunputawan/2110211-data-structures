void replace(const T& x, list<T>& y) {
  //write your code here
  T *tmpY = new T[y.size()];
  CP:list<T>::iterator it = y.begin();
  for(size_t i=0; i<y.size(); i++) {
    tmpY[i] = *(it++);
  }

  it = begin();
  while(it != end()) {
    if(*it == x) {
      it = erase(it);
      for(size_t i=0;i<y.size();i++) {
        insert(it, tmpY[i]);
      }
    }
    else {
      it++;
    }
  }
  
}

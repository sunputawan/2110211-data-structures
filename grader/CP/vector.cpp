#include <iostream>

namespace CP {
    template <typename T>
    class vector {
        protected:
            T *mData;
            size_t mCap;
            size_t mSize;

            void rangeCheck(int n) {
                if(n < 0 || ((size_t) n) >= mSize) {
                    throw std::out_of_range("Index out of range");
                }
            }
            void expand(size_t capacity) {
                T *arr = new T[capacity]();
                for(size_t i=0; i<mSize; i++) {
                    arr[i] = mData[i];
                }
                delete [] mData;
                mData = arr;
                mCap = capacity;
            }
            void ensureCapacity(size_t capacity) {
                if(capacity > mCap) {
                    size_t s = (capacity > 2 * mCap) ? capacity : 2*mCap;
                    expand(capacity);
                }
            }
        public:
            vector() {
                int cap = 1; 
                mData = new T[cap]();
                mCap = 1;
                mSize = 0;
            }
            vector(size_t cap) {
                mData = new T[cap]();
                mCap = cap;
                mSize = cap;
            }
            vector(const vector<T> &a) {
                mData = new T[a.capacity()]();
                mCap = a.mCap();
                mSize = a.mSize();
                for(size_t i=0;i<mSize;i++) {
                    mData[i] = a[i];
                }
            }
            ~vector() {
                delete [] mData;
            }

            T& at(int index) {
                rangeCheck(index);
                return mData[index];
            }
            T& operator[](int index) {
                return mData[index];
            }
            void operator=(const vector<T> &other) {
                if(mData != other.mData) {
                    delete [] mData;
                }
            }

            void push_back(const T& element) {
                ensureCapacity(mSize+1);
                mData[mSize++] = element;
            }
            void pop_back() {
                mSize--;
            }
            void print() {
                for(size_t i=0;i<mSize;i++) {
                    std::cout<<mData[i]<<' ';
                }
                std::cout<<'\n';
            }
            bool empty() {
                return mSize == 0;
            }
            size_t size() {
                return mSize;
            }
            size_t capacity() {
                return mCap;
            }
    };
}

int main() {
    CP::vector<int> v;
    for(int i=0;i<100000;i++) {
        v.push_back(i);
        //v.print();
    }
        return 0;
}
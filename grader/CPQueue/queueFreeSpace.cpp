#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> v = {1};
int main() {
    for(int i=0;i<40;i++) {
        v.push_back(2*v[v.size()-1]);
    }
    int n; cin>>n;
    long long mSize = 0, mCap = 1;
    while(n--) {
        int a,x; cin>>a>>x;
        if(a == 0) {
            mSize += x;
            if(mCap < mSize) {
                mCap = *lower_bound(v.begin(), v.end(), mSize);
            }
        }
        else {
            mSize -= x;
        }
    }

    cout<< mCap - mSize << '\n';

    return 0;
}
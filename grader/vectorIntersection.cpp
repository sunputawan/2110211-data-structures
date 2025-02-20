#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
vector<int> a,b;
set<int> s;
bool binarySearch(vector<int> &v, int key) {
    int l = 0, r = v.size()-1;
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (v[mid] == key)
            return true;
        if (v[mid] > key) {
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return false;
}
int main() {
    int m,n;
    cin>>m>>n;
    if(m >= n) {
        while(m--) {
            int val; cin>>val;
            a.push_back(val);
        }
        while(n--) {
            int val; cin>>val;
            b.push_back(val);
        }
    }
    else {
        while(m--) {
            int val; cin>>val;
            b.push_back(val);
        }
        while(n--) {
            int val; cin>>val;
            a.push_back(val);
        }
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int x:a) {
        if(binarySearch(b,x)) {
            s.insert(x);
        }
    }

    for(int x:s) {
        cout<<x<<' ';
    }
    cout<<'\n';
    return 0;
}
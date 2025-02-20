#include <iostream>
#include <algorithm>

using namespace std;
int a[10005],m,n;
bool binarySearch(int key,int start) {
    int l=start, r = n-1;
    while(l <= r) {
        int mid = l+ (r-l)/2;
        //cout<<l<<' '<<r<<' '<<mid<<'\n';
        if(a[mid] == key) {
            return true;
        }
        else if(a[mid] > key) {
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return false;
}
int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);
    while(m--) {
        int sum; cin>>sum;
        bool exist = false;
        for(int i=0;i<n;i++) {
            int key = sum - a[i];
            //cout<<a[i]<<' '<<key<<'\n';
            if(binarySearch(key,i+1)) {
                cout << "YES\n";
                exist = true;
                break;
            }
        }
        if(!exist) {
            cout << "NO\n";
        }
    }

    return 0;
}
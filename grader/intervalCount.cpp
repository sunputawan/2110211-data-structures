#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[200005];
int n,m,k;
vector<int> ans;
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    cin>>n>>m>>k;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr, arr+n);

    while(m--) {
        int p; cin>>p;
        int leftBound = p-k, rightBound = p+k;
        int leftIdx = lower_bound(arr, arr+n, leftBound) - arr;
        int rightIdx = upper_bound(arr, arr+n, rightBound) - arr;
        ans.push_back(rightIdx - leftIdx);
    }

    for(int x:ans) {
        cout<<x<<' ';
    }
    cout<<'\n';
    return 0;
}
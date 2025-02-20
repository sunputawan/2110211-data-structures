#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int a[1000005];
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,w; cin>>n>>w;
    for(int i=0;i<=min(w,n-1);i++) {
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    cout<<v[w/2]<<' ';

    for(int i=w+1;i<n;i++) {
        cin>>a[i];
        v.erase(lower_bound(v.begin(),v.end(),a[i-w-1]));
        v.insert(lower_bound(v.begin(),v.end(),a[i]), a[i]);
        cout<<v[w/2]<<' ';
    }
    cout<<'\n';
    return 0;
}
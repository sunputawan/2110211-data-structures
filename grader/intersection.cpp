#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
vector<int> a,b,ans;
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int x; cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<m;i++) {
        int x; cin>>x;
        b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0,j=0;
    while(i!=a.size() && j!=b.size()) {
        if(a[i] == b[j]) {
            ans.push_back(a[i]);
            i++,j++;
        }
        else if(a[i] > b[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    
    for(int i=0;i<ans.size();i++) {
        if(i==0 || ans[i] != ans[i-1]) {
            cout<<ans[i]<<' ';
        }
    }
    cout<<'\n';
    return 0;
}
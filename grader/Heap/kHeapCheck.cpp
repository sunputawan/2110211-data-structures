#include <iostream>
#include <queue>

using namespace std;
int main() {
    int m; cin>>m;
    while(m--) {
        int n,k; cin>>n>>k;
        vector<int> mData(n);
        for(int i=0;i<n;i++) {
            cin>>mData[i];
        }
        queue<int> q; q.push(0);
        bool isFalse = false;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            //cout<<"front "<<x<<'\n';
            for(int i=1;i<=k;i++) {
                if(x*k+i >= mData.size()) {
                    break;
                }
                if(mData[x] < mData[x*k+i]) {
                    //cout<<"doo : "<<x<<' '<<x*k+i<<'\n';
                    isFalse = true;
                    break;
                }
                q.push(x*k+i);
            }
            if(isFalse) {
                break;
            }
        }
        if(isFalse) {
            cout<<"false\n";
        }
        else {
            cout<<"true\n";
        }
    }
}
#include <iostream>
#include <vector>

using namespace std;
vector<int> col;
int main() {
    int n,pos,color; cin>>n>>pos>>color;
    for(int i=0;i<n;i++) {
        int x; cin>>x;
        col.push_back(x);
    }
    int lsum = 0, rsum = 0;
    int l = pos-1, r = pos;
    while(l >= 0) {
        if(col[l] == color) {
            lsum++;
        }
        l--;
    }
    while(r < n) {
        if(col[r] == color) {
            rsum++;
        }
        r++;
    }

    if(lsum + rsum < 2) {
        col.insert(col.begin() + pos, color);
        for(int i=0;i<=n;i++) {
            cout<<col[i]<<' ';
        }
        cout<<'\n';
        return 0;
    }
    else {
        while(col[l] == col[r]) {
            
        }
    }

    return 0;
}
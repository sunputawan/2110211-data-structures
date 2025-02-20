#include <iostream>

using namespace std;
int n,m,k;
int qsum[1005][1005];
int main() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>qsum[i][j];
            qsum[i][j] += qsum[i-1][j] + qsum[i][j-1] - qsum[i-1][j-1];
        }
    } 
    while(k--) {
        int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
        r1++; c1++; r2++; c2++;
        cout<<qsum[r2][c2] - qsum[r1-1][c2] - qsum[r2][c1-1] + qsum[r1-1][c1-1]<<'\n';
    }

    return 0;
}
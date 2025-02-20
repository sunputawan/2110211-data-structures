#include <iostream>

using namespace std;
int arr[105][105], dp[105][105];
int main() {
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cin>>arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + arr[i][j];
        }
    }
    int mx = -9999999;
    for(int j=1;j<=n;j++) {
        mx = max(mx, dp[n][j]);
    }

    cout<<mx<<'\n';

    return 0;
}
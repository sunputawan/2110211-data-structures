#include <iostream>

using namespace std;
int arr[505][505], dp[505][505];
int main() {
    int m,n; cin>>m>>n;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            cin>>arr[i][j];
        }
    }
    
    dp[1][1] = arr[1][1];
    for(int i=2;i<=m;i++) {
        dp[i][1] = dp[i-1][1] + arr[i][1];
    }
    for(int j=2;j<=n;j++) {
        dp[1][j] = dp[1][j-1] + arr[1][j];
    }

    for(int i=2;i<=m;i++) {
        for(int j=2;j<=n;j++) {
            dp[i][j] = max(arr[i][j]*2 + dp[i-1][j-1] , max(dp[i-1][j], dp[i][j-1]) + arr[i][j]);
        }
    }

    cout<<dp[m][n]<<'\n';

    return 0;
}
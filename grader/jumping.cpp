#include <iostream>

using namespace std;
int a[1000005], dp[1000005];
int main() {
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }

    dp[1] = a[1]; dp[2] = a[1]+a[2]; dp[3] = max(dp[1], dp[2]) + a[3];

    for(int i=4;i<=n;i++) {
        dp[i] = max(dp[i-3], max(dp[i-2], dp[i-1])) + a[i];
    }

    cout<<dp[n]<<'\n';

    return 0;
}
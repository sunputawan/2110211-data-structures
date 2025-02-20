#include <iostream>
#include <algorithm>
#define MININT -999999

using namespace std;
int dp[4005];
int portion[3];
int main() {
    int n; cin>>n>>portion[0]>>portion[1]>>portion[2];
    sort(portion,portion+3);
    for(int i=1;i<=n;i++) {
        dp[i] = MININT;
    }
    dp[0] = 0;
    for(int i=1;i<=n;i++) {
        if(i>=portion[0]) {
            dp[i] = dp[i-portion[0]] + 1;

        }
        if(i>=portion[1]) {
            dp[i] = max(dp[i-portion[0]], dp[i-portion[1]]) + 1;
        }
        if(i>=portion[2]) {
            dp[i] = max(dp[i-portion[0]], max(dp[i-portion[1]], dp[i-portion[2]])) + 1;
        }
    }

    cout<<dp[n]<<'\n';
    return 0;
}
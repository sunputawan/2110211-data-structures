#include <iostream>
#define MOD 100000007

using namespace std;
long long dp00[10000005];
long long dp01[10000005];

int main() {
    dp00[2] = 3;
    dp01[2] = 4;
    int n; cin>>n;
    for(int i=3;i<=n;i++) {
        dp00[i] = (dp00[i-1] + dp01[i-1]) % MOD;
        dp01[i] = (dp00[i-1] * 2 + dp01[i-1]) % MOD;
        //cout<<dp00[i]<<' '<<dp01[i]<<'\n';
    }
    cout<<(dp00[n]+dp01[n]) % MOD<<'\n';
}
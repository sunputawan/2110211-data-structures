#include <iostream>
#define MOD 100000007

using namespace std;
int dp0[5005], dp1[5005];
int main() {
    int n,k; cin>>n>>k;
    dp0[1] = 1;
    dp1[1] = 1;
    for(int i=2;i<=k;i++) {
        dp0[i] = (dp0[i-1] + dp1[i-1]) % MOD;
        dp1[i] = 1;
        //cout<<i<<" : "<<dp0[i]<<' '<<dp1[i]<<'\n';
    }

    for(int i=k+1;i<=n;i++) {
        dp0[i] = (dp0[i-1] + dp1[i-1]) % MOD;
        dp1[i] = (dp0[i-k] + dp1[i-k]) % MOD;
        //cout<<i<<" : "<<dp0[i]<<' '<<dp1[i]<<'\n';
    }

    cout<<(dp0[n] + dp1[n]) % MOD <<'\n';
    
}
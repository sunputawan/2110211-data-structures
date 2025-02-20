#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    long long n,k; cin>>n>>k;
    if(k==1) {
        cout<<n-1<<'\n';
    }
    else if(n==1) {
        cout<<0<<'\n';
    }
    else {
        vector<long long> v;
        long long x = 0;
        while(x <= 2e17) {
            //cout<<x<<'\n';
            v.push_back(x);
            x = x*k+1;
        }
        cout<<upper_bound(v.begin(),v.end(),n-1)- 1 - v.begin()<<'\n';
    }
    
    return 0;
}
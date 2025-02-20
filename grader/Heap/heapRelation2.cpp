#include <iostream>
#include <vector>
using namespace std;
int relation(long long S, long long a, long long b) {
    if(a > b) swap(a,b);
    if((b-1)/S == a) {
        return 1;
    }

    if(a == 0) return 2;
    long long x = b;
    while(x > 0) {
        x = (x-1)/S;
        if(x == a) return 2;
    }

    long long m = a,n = b;
    while(m > 0 && n > 0) {
        m = (m-1)/S;
        n = (n-1)/S;
    }
    if(m == n) {
        return 4;
    }
    return 3;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin>>n;
    long long S,a,b;
    while (n--) {
        cin >> S >> a >> b;
        cout << relation(S,a,b) << " ";
    }
    cout << endl;
}
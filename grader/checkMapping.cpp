#include <iostream>
#include <set>

using namespace std;
set<int> a,b;
int main() {
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
        int x; cin >> x;
        b.insert(x);
        a.insert(i);
    }

    if(a == b) {
        cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
    }
    return 0;
}
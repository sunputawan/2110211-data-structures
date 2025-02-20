#include <iostream>
#include <set>

using namespace std;
set<int> s;
int n,k;
void go(int idx) {
    if(idx >= n) return;
    s.erase(idx);
    go(idx*2+1);
    go(idx*2+2);

}
int main() {
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        s.insert(i);
    }
    go(k);
    cout<<s.size()<<'\n';
    for(int x:s) {
        cout<<x<<' ';
    }
}
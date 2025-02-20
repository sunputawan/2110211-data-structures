#include <iostream>
#include <map>

using namespace std;
map<int,int> mp;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m,n; cin>>n>>m;
    while(n--) {
        int l,r; cin>>l>>r;
        mp[l] = 1;
        if(mp.find(r+1) == mp.end())
            mp[r+1] = -1;
    }
    auto it = mp.begin();
    mp[(it -> first) - 1] = -1;

    while(m--) {
        int key; cin>>key;
        map<int,int>::iterator it = mp.upper_bound(key);
        if(it != mp.begin()) it--;
        if(it -> second == 1) {
            cout<<"1 ";
        }
        else {
            cout<<"0 ";
        }
    }
    cout<<'\n';
    return 0;
}
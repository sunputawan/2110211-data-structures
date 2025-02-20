#include <iostream>
#include <map>

using namespace std;
map<string,int> mp;
int main() {
    int n; cin>>n;
    while(n--) {
        string name; cin>>name;
        if(mp.find(name) == mp.end()) {
            mp[name] = 0;
        }
        mp[name] += 1;
    }
    int mx = -999999;
    string mxName;
    for(auto x:mp) {
        if(x.second >= mx) {
            mx = x.second;
            mxName = x.first;
        }
    }

    cout<<mxName<<' '<<mx<<'\n';

    return 0;

}
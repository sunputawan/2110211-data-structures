#include <iostream>
#include <map>

using namespace std;
map<string,int> mp;
int main() {
    int n; cin>>n;
    for(int i=0;i<n;i++) {
        string str; cin>>str;
        if(mp.find(str) == mp.end()) {
            mp[str] = 0;
        }
        mp[str]++;
    }

    for(auto words:mp) {
        if (words.second > 1) {
            cout<<words.first<<' '<<words.second<<'\n';
        }
    }
    return 0;
}
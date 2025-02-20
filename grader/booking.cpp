#include <iostream>
#include <set>
#include <vector>
#include <utility>

using namespace std;
set<pair<string,string>> s;
vector<pair<string,string>> tmp;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m; cin>>n>>m;
    while(n--) {
        string a,b; cin>>a>>b;
        s.insert({a,b});
    }

    while(m--) {
        int amount; cin>>amount;
        bool success = true;
        while(amount--) {
            string a,b; cin>>a>>b;
            if(s.find({a,b}) == s.end()) {
                success = false;
            }
            tmp.push_back({a,b});
        }
        if(success) {
            cout<<"YES\n";
            for(pair<string,string> x:tmp) {
                s.erase(x);
            }
        }
        else {
            cout<<"NO\n";
        }
        tmp.clear();
    }

    return 0;
}
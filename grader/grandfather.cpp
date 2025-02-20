#include <iostream>
#include <map>

using namespace std;
map<long long, long long> mp; //<son, father>
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m; cin>>n>>m;
    while(n--) {
        long long f,s; cin>>f>>s;
        mp[s] = f;
    }
    while(m--) {
        long long a,b;
        cin>>a>>b;
        if(a == b) {cout<<"NO\n"; continue;}

        map<long long, long long>::iterator aFather = mp.find(a), bFather = mp.find(b);
        if(aFather == mp.end() || bFather == mp.end()) {
            cout<<"NO\n";
            continue;
        }

        map<long long, long long>::iterator aFatherGrand, bFatherGrand;
        aFatherGrand = mp.find(aFather -> second);
        bFatherGrand = mp.find(bFather -> second);
        if(aFatherGrand == mp.end() || bFatherGrand == mp.end() || aFatherGrand -> second != bFatherGrand -> second) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }

    return 0;
}
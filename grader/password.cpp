#include <iostream>
#include <set>

using namespace std;
int code[100005];
set<string> s;
void decode(string &str) {
    int n = str.size();
    for(int i=0;i<n;i++) {
        str[i] = (str[i] - 'a' - code[i] + 26*10000) % 26 + 'a';
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,l; cin>>n>>m>>l;
    for(int i=0;i<l;i++) {
        cin>>code[i];
    }
    for(int i=0;i<n;i++) {
        string str; cin>>str;
        decode(str);
        s.insert(str);
    }
    while(m--) {
        string key; cin>>key;
        if(s.find(key) != s.end()) {
            cout<<"Match\n";
        }
        else {
            cout<<"Unknown\n";
        }
    }
}

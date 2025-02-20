#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m; cin>>n>>m;
    while(n--) {
        int y,m; cin>>y>>m;
        v.push_back(y*100 + m);
    }

    sort(v.begin(),v.end());
    while(m--) {
        int y,m; cin>>y>>m;
        int key = y*100 + m;
        vector<int>::iterator it = upper_bound(v.begin(), v.end(), key);
        if(it == v.begin()) {
            cout<<"-1 -1 ";
        }
        else {
            it--;
            if(*it == key) {
                cout<<"0 0 ";
            }
            else {
                cout<<(*it)/100<<' '<<(*it)%100<<' ';
            }
        }
    }
    cout<<'\n';
    return 0;
}
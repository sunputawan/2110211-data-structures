#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void member_multiply(vector<int> &v, vector<pair<vector<int>::iterator,int>> &multiply) {
    //write your code here
    sort(multiply.begin(),multiply.end());
    vector<int> result;

    vector<int>::iterator vit = v.begin();
    for(auto x:multiply) {
        vector<int>::iterator it = x.first;
        int cnt = x.second+1;
        while(vit != it) {
            result.push_back(*vit);
            vit++;
        }
        // cout<<"pre : ";
        // for(auto x:result) {
        //     cout<<x<<' ';
        // }
        //cout<<'\n';
        while(cnt--) {
            result.push_back(*it);
        }
        vit++;
        // cout<<"post : ";
        // for(auto x:result) {
        //     cout<<x<<' ';
        // }
        // cout<<'\n';
    }
    while(vit != v.end()) {
        result.push_back(*vit);
        vit++;
    }
    v = result;

}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator,int>> multiply(m);
    for (int i = 0;i < n;i++) cin >> v[i];
        for (int i = 0;i < m;i++) {
            int a,b;
            cin >> a >> b;
            multiply[i].first = v.begin()+a;
            multiply[i].second = b;
        }
        member_multiply(v,multiply);
        cout << "======= result ========" << endl;
        cout << v.size() << endl;
        for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}
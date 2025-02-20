#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int main() {
    int q;
    cin >> q;
    while(q--) {
        string opr;
        cin >> opr;
        if(opr == "sa") {
            sort(v.begin(), v.end());
        }
        else if(opr == "sd") {
            sort(v.rbegin(), v.rend());
        }
        else if(opr == "r") {
            reverse(v.begin(), v.end());
        }
        else if(opr == "pb") {
            int val; cin>>val;
            v.push_back(val);
        }
        else if(opr == "d") {
            int idx; cin>>idx;
            v.erase(v.begin()+idx);
        }

    }

    for(int x:v) {
        cout << x << ' ';
    }
    cout<<'\n';
    return 0;
}
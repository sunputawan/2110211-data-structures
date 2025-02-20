#include <iostream>
#include <vector>
#include <map>

using namespace std;
map<int,int> mark, timeToSpeed, speedToTime;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k; cin>>n>>m>>k;
    mark.insert({0,k});
    while(n--) {
        int t,d; cin>>t>>d;
        mark.insert({t,-d});
    }
    int sum = 0;
    for(auto [t,d]:mark) {
        timeToSpeed.insert({t,max(0, sum+d)});
        speedToTime.insert({max(0, sum+d), t});
        sum = max(0, sum+d);
    }

    // for(auto [t,d]:speedToTime) {
    //     cout<<"log : "<<t<<' '<<d<<'\n';
    // }

    while(m--) {
        int a,q; cin>>a>>q;
        if(a==1) {
            map<int,int>::iterator it = timeToSpeed.upper_bound(q);
            if(it == timeToSpeed.begin()) {
                cout << k << '\n';
            }
            else {
                it--;
                cout << it -> second << '\n';
            }
        }
        else {
            map<int,int>::iterator it = speedToTime.lower_bound(q);
            if(it == speedToTime.begin()) {
                cout << it -> second + 1 << '\n';
            }
            else {
                it--;
                cout << it -> second << '\n';
            }
        }
    }

    return 0;
}
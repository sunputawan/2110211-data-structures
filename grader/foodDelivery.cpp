#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int p[100005];
vector<int> result;
queue<int> q1,q2;
int total = 0;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>p[i];
    }
    while(n--) {
        int opr; cin>>opr;
        if(opr == 1) {
            int app,cost; cin>>app>>cost;
            if(app == 1) q1.push(cost);
            else q2.push(cost);
        }
        else {
            if(q2.empty()) {
                total += q1.front();
                result.push_back(total);
                q1.pop();
            }
            else if(q1.empty()) {
                total += q2.front();
                result.push_back(total);
                q2.pop();
            }
            else {
                if(q1.front() <= q2.front()) {
                    total += q1.front();
                    result.push_back(total);
                    q1.pop();
                }
                else {
                    total += q2.front();
                    result.push_back(total);
                    q2.pop();
                }
            }
        }
    }

    for(int i=0;i<m;i++) {
        vector<int>::iterator it = lower_bound(result.begin(),result.end(),p[i]);
        if(it == result.end()) cout<<"-1 ";
        else cout<< it-result.begin() + 1<<' ';
    }
    cout<<'\n';

    return 0;
}
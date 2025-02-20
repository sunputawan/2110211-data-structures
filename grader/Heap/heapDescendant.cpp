#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long int n,a; cin>>n>>a;
    queue<long long int> q;
    q.push(a);
    while(!q.empty()) {
        long long int x = q.front(); q.pop();
        v.push_back(x);
        if(2*x+1 < n) {
            q.push(2*x+1);
        }
        if(2*x+2 < n) {
            q.push(2*x+2);
        }
    }

    cout<<v.size()<<'\n';
    for(long long int x:v) {
        cout<<x<<' ';
    }
}
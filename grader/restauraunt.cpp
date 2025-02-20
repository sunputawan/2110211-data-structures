#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int t[1000005];
struct Seat {
    int endTime;
    int seatNumber;
    bool operator<(const Seat &other) const {
        return endTime > other.endTime;
    }
};
priority_queue<Seat,vector<Seat>> pq;
vector<int> ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m; cin>>n>>m;
    for(int i=0;i<min(n,m);i++) {
        cin>>t[i];
        pq.push({t[i],i});
        //cout<<"in : "<<i<<" start at "<< 0 <<'\n';
    }
    m -= n;
    while(!pq.empty()) {
        Seat leaveCustomer = pq.top();
        pq.pop();
        ans.push_back(leaveCustomer.endTime - t[leaveCustomer.seatNumber]);
        if(m > 0) {
            //cout<<"out : "<<leaveCustomer.seatNumber<<" end at "<< leaveCustomer.endTime<<'\n';
            pq.push({leaveCustomer.endTime + t[leaveCustomer.seatNumber], leaveCustomer.seatNumber});
            //cout<<"in : "<<leaveCustomer.seatNumber<<" start at "<< leaveCustomer.endTime <<'\n';
            m--;
            //cout<<"remaining Customer : "<<m<<'\n';
        }
    }

    sort(ans.begin(),ans.end());
    for(int x:ans) {
        cout<<x<<'\n';
    }

    return 0;
}
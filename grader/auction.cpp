#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;
struct BidAction {
    int user;
    int amount;
    bool operator<(const BidAction &o) const {
        return amount < o.amount || (amount == o.amount && user < o.user);
    }
};
map<int,map<int,int>> inValidBids;
vector<set<int>> totalUserWon(1000005);
vector<set<int>> totalBidWon(1000005);
int k[1000005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,a; cin>>n>>m>>a;
    for(int i=1;i<=n;i++) {
        cin>>k[i];
        inValidBids[i] = {};
    }
    while(a--) {
        char action; cin>>action;
        if(action == 'B') {
            int user,id,amount; cin>>user>>id>>amount;
            inValidBids[id][user] = amount;
        }
        else {
            int user,id; cin>>user>>id;
            inValidBids[id].erase(user);
        }
    }

    // for(auto x:inValidBids) {
    //     cout<<"id : "<<x.first<<'\n';
    //     for(auto bid:x.second) {
    //         cout<<"user : "<<bid.first<<'('<<bid.second<<")\n";
    //     }
    //     cout<<'\n';
    // }

    for(int i=1;i<=n;i++) {
        priority_queue<BidAction> pq;
        for(auto bid:inValidBids[i]) {
            int user = bid.first;
            int amount = bid.second;
            pq.push({user,amount});
        }
        while(!pq.empty() && k[i]--) {
            totalUserWon[i].insert(pq.top().user);
            pq.pop();
        }
    }

    for(int i=1;i<=n;i++) {
        for(int user:totalUserWon[i]) {
            totalBidWon[user].insert(i);
        }
    }

    for(int i=1;i<=m;i++) {
        if(totalBidWon[i].empty()) {
            cout<<"NONE\n";
        }
        else {
            for(int id:totalBidWon[i]) {
                cout<<id<<' ';
            }
            cout<<'\n';
        }
    }

    return 0;

}
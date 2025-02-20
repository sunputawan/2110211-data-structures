#include <iostream>
#include <set>
#include <map>

using namespace std;
set<int> ourGoods;
map<int,int> idToAmount;
struct Goods {
    int id;
    int amount;
    bool operator<(const Goods &o) const {
        return amount < o.amount || (amount == o.amount && id < o.id);
    }
};
set<Goods> sys;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m; cin>>n>>m;
    while(n--) {
        int id; cin>>id;
        ourGoods.insert(id);
    }

    while(m--) {
        int opr; cin>>opr;
        if(opr == 1) {
            int id, amount; cin>>id>>amount;
            if(ourGoods.find(id) != ourGoods.end()) {
                if(idToAmount.find(id) == idToAmount.end()) {
                    idToAmount[id] = 0;
                }
                Goods tmp = {id,idToAmount[id]};
                if(sys.find(tmp) != sys.end()) {
                    sys.erase(tmp);
                }
                idToAmount[id] += amount;
                sys.insert({id,idToAmount[id]});
            }
        }
        else {
            int k; cin>>k;
            Goods tmp = {0, k};
            set<Goods>::iterator it = sys.lower_bound(tmp);
            if(it == sys.begin()) {
                cout<<"NONE\n";
            }
            else {
                it--;
                cout<<it -> id<<'\n';
            }
        }
        // cout<<"set: ";
        // for(auto x:sys) {
        //     cout<<x.id<<" ("<<x.amount<<"), ";
        // }
        // cout<<'\n';
        // cout<<"map: ";
        // for(auto x:idToAmount) {
        //     cout<<x.first<<" ["<<x.second<<"], ";
        // }
        // cout<<'\n';
    }
}
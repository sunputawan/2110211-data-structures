#include <iostream>
#include <map>

using namespace std;
map<int,int> cards;
int lastRound = -1;
int card,cnt,val;
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); 
    int n,m; cin>>n>>m;
    while(n--) {
        cin>>card;
        if(cards.find(card) == cards.end()) {
            cards[card] = 0;
        }
        cards[card]++;
    }

    for(int i=1;i<=m;i++) {
        cin>>cnt;
        if(lastRound == -1) {
            while(cnt--) {
                cin>>val;
                 map<int,int>::iterator it = cards.upper_bound(val);
                if(it != cards.end()) {
                    it->second--;
                    if(it->second == 0)
                        cards.erase(it);
                }
                else {
                    lastRound = i;
                }
            }
        }
    }
    if(lastRound == -1) {
        lastRound = m+1;
    }

    cout<<lastRound<<'\n';
}
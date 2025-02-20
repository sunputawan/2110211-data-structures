#include <iostream>
#include <map>
#include <set>

using namespace std;
map<int,set<int>> characters;
map<int,int> typeToPower;
int power[500005];
int type[500005];
int main() {
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++) {
        characters[1].insert(i);
        typeToPower[i] = 1;
    }
    for(int i=0;i<n;i++) cin>>power[i];
    for(int i=0;i<n;i++) cin>>type[i];

    for(int i=0;i<n;i++) {
        int currentPower = typeToPower[type[i]];
        if(power[i] > currentPower) {
            characters[currentPower].erase(type[i]);
            if(characters[currentPower].empty()) {
                characters.erase(currentPower);
            }
            characters[power[i]].insert(type[i]);
            typeToPower[type[i]] = power[i];
        }

        cout<<characters.begin() -> first<<' ';
    }

    return 0;
}
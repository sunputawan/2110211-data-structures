#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
map<string,int> score;
vector<int> totalScore;
int min(int a,int b) {
    return (a<b) ? a:b;
}
int main() {
    int n,k;
    cin>>n>>k;
    while(n--) {
        string name; cin>>name;
        if(score.find(name) == score.end()) {
            score[name] = 0;
        }
        score[name] += 1;
    }

    for(auto x:score) {
        totalScore.push_back(x.second);
    }
    sort(totalScore.begin(), totalScore.end(), greater<int>());
    int mx = totalScore[0];
    cout<<totalScore[min(k-1, totalScore.size()-1)]<<'\n';

    return 0;

}
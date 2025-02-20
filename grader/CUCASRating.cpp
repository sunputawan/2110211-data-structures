#include <iostream>
#include <iomanip>
#include <map>
#include <utility>


using namespace std;
int n;
map<int,pair<int,int>> idMap;
map<string,pair<int,int>>  teacherMap;
int main() {
    cout << std::fixed << std::setprecision(2);
    cin>>n;
    while(n--) {
        int id,rating;
        string teacher;
        cin>>id>>teacher>>rating;
        if(idMap.find(id) == idMap.end()) {
            idMap[id] = {rating, 1};
        }
        else {
            int newRating = idMap[id].first + rating;
            int newSize = idMap[id].second + 1;
            idMap[id] = {newRating, newSize};
        }

        if(teacherMap.find(teacher) == teacherMap.end()) {
            teacherMap[teacher] = {rating, 1};
        }
        else {
            int newRating = teacherMap[teacher].first + rating;
            int newSize = teacherMap[teacher].second + 1;
            teacherMap[teacher] = {newRating, newSize};
        }
    }

    for(auto x:idMap) {
        cout<<x.first<<' '<<(x.second.first + 0.0)/x.second.second<<'\n';
    }
    for(auto x:teacherMap) {
        cout<<x.first<<' '<<(x.second.first + 0.0)/x.second.second<<'\n';
    }

    return 0;
}
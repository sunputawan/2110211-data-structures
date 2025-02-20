#include <vector>
#include <map>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    map<T,int> mp; 
    for(size_t i=0;i<A.size();i++) {
        mp[A[i]] = i;
    }
    for(size_t i=0;i<B.size();i++) {
        if(mp.find(B[i]) == mp.end()) mp[B[i]] = mp.size();
    }
    v.resize(mp.size());
    for(auto x:mp) {
        v[x.second] = x.first;
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    map<T,pair<int,int>> mp;
    for(size_t i=0;i<A.size();i++) {
        mp[A[i]] = {i,0};
    }
    size_t size = 0;
    for(size_t i=0;i<B.size();i++) {
        if(mp.find(B[i]) != mp.end()) {
            mp[B[i]] = {mp[B[i]].first, 1};
        }
    }
    set<pair<int,T>> s;
    for(auto x:mp) {
        if(x.second.second == 1) s.insert({x.second.first, x.first});
    }
    for(auto x:s) {
        v.push_back(x.second);
    }
    return v;
}

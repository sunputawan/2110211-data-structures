#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool binarySearch(vector<int> &pos, int key) {
    int l = 0, r = pos.size()-1;
    while(l<=r) {
        int mid = l + (r-l)/2;
        if(pos[mid] == key) {
            return true;
        }
        else if (pos[mid] > key) {
            r = mid - 1;
        }
        else {
             l = mid + 1;
        }
    }
    return false;
}
void list_erase(vector<int> &v, vector<int> &pos) {
    //write your code here
    int n = v.size();
    vector<int> tmp;
    sort(pos.begin(), pos.end());
    for(int i=0;i<n;i++) {
        if(!binarySearch(pos, i)) {
            tmp.push_back(v[i]);
        }
    }
    v = tmp;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;

    vector<int> v(n), pos(m);
    for (int i = 0;i < n;i++) cin >> v[i];
    for (int i = 0;i < m;i++) cin >> pos[i];

    list_erase(v,pos);
    cout << "After call list_erase" << endl << "Size = " << v.size() << endl;
    for (auto &x : v) cout << x << " ";
    cout << endl;
}
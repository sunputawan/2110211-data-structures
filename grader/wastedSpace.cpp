#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
vector<int> v;
int main() {
    int n; cin>>n;
    for(int i=0;i<=31;i++) {
        v.push_back(pow(2,i));
        //cout<<v[i]<<'\n';
    }
    vector<int>::iterator it = lower_bound(v.begin(),v.end(),n);
    cout<<*it - n<<'\n';

    return 0;
}
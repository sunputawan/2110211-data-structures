#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {
    //write your code only in this function
    b--;
    for(vector<int>::iterator i=a;i<=((b-v.begin())+(a-v.begin()))/2 + v.begin();i++) {
        int tmp;
        tmp = v[i-v.begin()];
        v[i-v.begin()] = v[(a-v.begin())+b-i];
        v[a-v.begin()+b-i] = tmp;
    }
}
int main() {
    //read input
    int n,a,b;
    cin >> n;
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    //call function
    reverse(v,v.begin()+a,v.begin()+b+1);
    //display content of the vector
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}
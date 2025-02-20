#include <iostream>
#include <vector>
using namespace std;
void remove_even(vector<int> &v,int a,int b) {
    if(a%2) a++;
    if(b%2) b--;
    vector<int> idx;
    for(int i=a;i<=b;i++) idx.push_back(i);

    for(int i=a;i<=b;i++) {
        v.erase(v.begin()+i);
        b--;
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
    remove_even(v,a,b);
    //display content of the vector
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}
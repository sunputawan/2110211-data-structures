#include <iostream>

using namespace std;
int parent(int n) {
    return (n-1)/2;
}
int main() {
    int n,m; cin>>n>>m;
    while(m--) {
        int a,b; cin>>a>>b;
        if(a == b) {
            printf("a and b are the same node\n");
            continue;
        }
        else if(a > b) {
            while(a > b) {
                a = parent(a);
            }
            if(a == b) {
                printf("b is an ancestor of a\n");
            }
            else {
                printf("a and b are not related\n");
            } 
        }
        else {
            while(b > a) {
                b = parent(b);
            }
            if(b == a) {
                printf("a is an ancestor of b\n");
            }
            else {
                printf("a and b are not related\n");
            }
        }
    }
}
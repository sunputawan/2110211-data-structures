#include <iostream>
#define MAXDAY 100005

long long a[100005];
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,start; cin>>n>>m>>start;
    while(n--) {
        int i,val; cin>>i>>val;
        a[i] = val;
    }
    a[0] = start;
    for(int i=0;i<MAXDAY;i++) {
        if(a[i] == 0) {
            a[i] = a[i-1];
        }

    }
    for(int i=0;i<MAXDAY;i++) {
        a[i] += a[i-1];
        //cout<<a[i]<<' ';
    }

    while(m--) {
        int p,x; cin>>p>>x;
        int day = lower_bound(a, a+x+1, p) - a;
        if(day == x+1) {
            day = lower_bound(a+x+1, a+MAXDAY, p+a[x]) - a;
            if(day == MAXDAY + 1) {
                day = (double(p - a[MAXDAY-1]) / a[MAXDAY-1] - a[MAXDAY-2]) + MAXDAY-1;
            }
        }
        cout<<day<<' ';
    }
    cout<<'\n';

}
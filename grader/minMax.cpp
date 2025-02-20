#include <iostream>
#define MIN -9999999

int arr[105][105];
using namespace std;
int main(){
    int n,m,r;
    cin>>n>>m>>r;
    for(int i=1; i<=n; i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    while(r--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;

        if(r1 > r2 || c1 > c2){
            cout<<"INVALID\n";
            continue;
        }
        if((r1 < 1 && r2 < 1) || (r1 > n && r2 > n) || (c1 < 1 && c2 < 1) || (c1 > m && c2 > m)){
            cout<<"OUTSIDE\n";
            continue;
        }

        int mx = MIN;
        for(int i=max(1,r1); i<=min(n,r2) ; i++){
            for(int j=max(1,c1); j<=min(m,c2); j++){
                mx = (arr[i][j] > mx) ? arr[i][j] : mx;
            }
        }
        cout<<mx<<'\n';
    }

    return 0;
}
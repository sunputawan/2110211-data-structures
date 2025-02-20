#include <iostream>

using namespace std;
int main() {
    int h,m,x;
    cin >> h >> m >> x;
    m += x;
    printf("%02d %02d", (h + m/60)%24, m%60);
}
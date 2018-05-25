#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int L, n, x, T;
        int minT = 0, maxT = 0;
        scanf("%d%d", &L, &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            minT = max(minT, min(x, L - x));
            maxT = max(maxT, max(x, L - x));
        }
        printf("%d %d\n", minT, maxT);
    }
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010];
int main() {
    int n, r;
    while(~scanf("%d%d", &r, &n) && r != -1 && n != -1) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        int ans = 0, t;
        for(int i = 0; i < n; i++) {
            ans ++;
            t = a[i];
            while(a[i] <= t+r && i < n) i++;
            if (a[i] > t+r) i--;
            t = a[i];
            while(a[i] <= t+r && i < n) i++;
            if (a[i] > t+r) i--;
        }
        printf("%d\n", ans);
    }
}

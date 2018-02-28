#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100010;
const int inf = 0x7fffffff;
struct node {
    int x, v;
} a[maxn];
bool cmp(node a, node b) {
    return a.x < b.x;
}

int binary(int l, int r, int v, bool lt) {
    if (l >= r) {
       return lt ? (a[r].x == v ? r : r-1) : r;
    }
    int m = (l + r) / 2;
    if (a[m].x < v) {
        return binary(m+1, r, v, lt);
    } else {
        return binary(l, m, v, lt);
    }
}
int main() {
    int t, n, R, maxx, l, r, x, y;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &R);
        maxx = 0;
        for(int i = 0; i < n; i++) {
           scanf("%d%d", &a[i].x, &a[i].v);
           if(a[i].v > maxx) maxx = a[i].v;
        }

        sort(a, a+n, cmp);

        int ans = inf;
        for(int i = 0; i < n; i++) {
            if (a[i].v == maxx) {
                x = max(0, a[i].x - R);
                y = min(a[n-1].x, a[i].x + R);
                l = binary(0, n-1, x, false);
                r = binary(0, n-1, y, true);
                int sum = 0, avg;
                for(int i = l ; i <= r; i++) {
                    sum += a[i].v;
                }
                avg = sum / (r - l + 1);
                avg = avg * (r - l + 1) == sum ? avg : avg + 1;
                ans = min(ans, avg);
            }
        }
        printf("%d\n", ans);
    }
}

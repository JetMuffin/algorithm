#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10000000;
int p[maxn];
int main() {
    int l = 9000000;
    int r = 10000000;
    memset(p, 0, sizeof(p));
    for(int i = l; i < r; i++) {
        p[i] = 1;
    }
    for(int i = 2; i < maxn; i++) {
        int x = i;
        for(int j = 2; j * j <= i; j++) {
            if (x % j == 0) {
                int cnt = 0;
                while(x % j == 0) {
                    x/=j;
                    cnt++;
                }
                p[i] *= (cnt+1);
            }
        }
        if (x != 1) {
            p[i] *= 2;
        }
    }
    int ans = 0;
    for(int i = l; i < r; i++) {
        ans = max(p[i/2] + p[i+1], ans);
        // cout << p[i/2] + p[i+1] << endl;
        if (i % 2 == 0) {
            if (p[i/2] + p[i+1] > 500) {
                cout << i << endl;
                break;
            }
        } else {
            if (p[i] + p[(i+1)/2] > 500) {
                cout << i << endl;
                break;               
            }
        }
    }
    cout << ans << endl;
}

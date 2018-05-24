#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
#define ll long long
int a[20];
int main() {
    int t, cas = 0;
    ll n, k, cnt;
    scanf("%d", &t);
    while(t--) {
        cas++;
        scanf("%lld", &n);
        k = n;
        vector<ll> v;
        while(k) {
            v.push_back(k%10);
            k /= 10;
        }
        cnt = v.size() - 1;
        for(; cnt >= 0 ; cnt--) {
            if (v[cnt] % 2 == 1) {
                break;
            }
        }
        if (cnt > 0) {
            ll a = pow(10, cnt);
            ll b = (n / a % 10 == 9) ? (n / a + 11) * a : (n / a + 1) * a;
            ll c = (n / a - 1) * a;
            ll d = 8;
            for(int i = 1; i < cnt; i++) {
                d = d * 10 + 8;
            }
            c = c + d;
            //cout << n << endl;
            //cout << b << " " << c << endl;
            printf("Case #%d: %lld\n", cas, min(abs(b - n), abs(n - c)));
        } else if (cnt == 0) {
            printf("Case #%d: %lld\n", cas, 1ll);
        } else {
            printf("Case #%d: %lld\n", cas, 0ll);
        }
    }
}

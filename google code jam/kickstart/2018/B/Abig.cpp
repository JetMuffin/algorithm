#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
#define ll unsigned long long
ll dp[21][4];
ll bit[21];
void init() {
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    dp[1][1] = 0;
    dp[1][2] = 1;
    dp[1][3] = 8;

    for(int i = 1; i <= 20; i++) {
        dp[i+1][0] = dp[i][0]*2 + dp[i][1] + dp[i][2];
        dp[i+1][1] = dp[i][0]*8 + dp[i][1]*9 + dp[i][3];
        dp[i+1][2] = dp[i][2] + dp[i][3];
        dp[i+1][3] = dp[i][2]*8 + dp[i][3]*8;
    }
}
ll calc(ll n) {
    int len = 0;
    ll ret = 0;
    ll x = n;
    while(n) {
        bit[len++] = n % 10;
        n/=10;
    }
    ll ans;
    bit[len] = 0;
    bool has = false;
    for(int i = len; i >= 1; i--) {
        if (bit[i] == 9) {
            ret += dp[i][2] * 8 + dp[i][3] * 8;
            has = true;
        } else {
            ret += dp[i][2] * bit[i] + dp[i][3] / 8 * 7 * bit[i];
        }
    }
    if (!has) {
        for(ll i = x/10*10; i <= x; i++) {
            if(i % 9 != 0) ret++;
        }
    }
    if (bit[0] == 9) ret--;
    return ret;
}
int main() {
    init();
    assert(dp[3][0] + dp[3][1] + dp[3][2] + dp[3][3] == 1000);
    int t, cas = 0;
    ll r, l;
    scanf("%d", &t);
    while(t--) {
        cas++;
        scanf("%lld%lld", &l, &r);
        printf("Case #%d: %lld\n", cas, calc(r) - calc(l-1));
    }
}

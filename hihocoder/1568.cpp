#include <iostream>
#include <cstdio>
using namespace std;
const int mod = 1000000007;
const int maxn = 800;
#define ll long long
ll fac[maxn], inv[maxn];
int cnt[25];
void init() {
	fac[0] = inv[0] = 1;
	for(int i = 1; i < maxn; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[1] = 1;
	for(int i = 2; i < maxn; i++) {
		inv[i] = inv[mod % i] * (mod - mod/i) % mod;
	}
	for(int i = 2; i < maxn; i++) {
		inv[i] = inv[i] * inv[i-1] % mod;
	}
}
int main() {
    init();
    int n, k;
    while(~scanf("%d%d", &n, &k)) {
        ll ans = 1;
        ans = (2*k+1) * fac[2*n] % mod;
        ans = ans * inv[n+k+1] % mod * inv[n-k] % mod;
        printf("%lld\n", ans);
    }
}

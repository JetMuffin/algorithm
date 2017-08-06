#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100010;
const int mod = 1000000007;
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
ll C(int n, int k) {
	return k > n ? 0 : fac[n] * inv[k] % mod * inv[n-k] % mod;
}

int main() {
	int t, n, k;
	init();
	scanf("%d", &t);
	while(t--) {
		while(~scanf("%d%d", &n, &k)) {
			memset(cnt, 0, sizeof(cnt));
			for(int i = 0; i < n; i++) {
				int x;
				scanf("%d", &x);
				for(int j = 0; j < 20; j++) {
					cnt[j] += (x >> j) & 1;
				}
			}
			ll b = 1, ans = 0;
			for(int j = 0; j < 20; j++) {
				ans = (ans + (C(n, k) - C(n - cnt[j], k) + mod) % mod * b % mod) % mod;
				b *= 2;
			}
			printf("%lld\n", ans);
		}
	}
}
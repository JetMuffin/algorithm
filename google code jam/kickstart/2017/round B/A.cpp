#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define mod 1000000007
ll b[10010];
void pre() {
	b[0] = 1;
	for(int i = 1; i <= 10000; i++) {
		b[i] = 2 * b[i-1] % mod;
	}
}
int main() {
	int t, cas = 0;
	scanf("%d", &t);
	int n;
	ll k;
	pre();
	while(t--) {
		cas++;
		scanf("%d", &n);
		ll one = 0;
		ll two = 0;
		for(int i = 0; i < n; i++) {
			scanf("%lld", &k);
			one = (one + (k * b[i]) % mod) % mod;
			two = (two + (-k * b[n-1-i]) % mod) % mod;
		}
		printf("Case #%d: %lld\n", cas, (one + two + mod)%mod);
	}
}
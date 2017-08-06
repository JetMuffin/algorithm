#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
const int maxn = 100010;
const ll mod = 1000000007;
ll a[maxn];
ll t[maxn];
void init() {
	t[0] = 1;
	for(int i = 1; i < maxn; i++) {
		t[i] = (2 * t[i-1]) % mod;
	}
}
int main() {
	int n, k;
	while(~scanf("%d%d", &n, &k)) {
		init();
		for(int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		sort(a, a+n);
		ll ans = 0;
		int p;
		for(int i = 0; i < n; i++) {
			if(a[i] > k / 2) break;
			p = upper_bound(a + i, a + n, k - a[i]) - a - 1;
			// cout<<a[i]<<" "<<k - a[i]<<" "<<i<<" "<<p<<endl;
			ans = (ans + t[p - i]) % mod;
		}
		printf("%lld\n", ans);
	}
}
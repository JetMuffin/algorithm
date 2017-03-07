#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int maxn = 1010;
const int inf = 0x3f3f3f;
ll n, m, k;
ll r[maxn], c[maxn];
int main() {
	while(~scanf("%lld%lld%lld", &n, &m, &k)) {
		for(int i = 0; i < k; i++) {
			scanf("%lld%lld", &r[i], &c[i]);
		}
		ll ans = n * (n + 1) / 2 * m * (m + 1) / 2;
		for(int i = 1; i < (1 << k); i++) {
			int num = __builtin_popcount(i);
			int x1 = inf, x2 = 0, y1 = inf, y2 = 0;
			for(int j = 0; j < k; j++) {
				if(i & (1 << j)) {
					if(x1 > r[j]) x1 = r[j];
					if(x2 < r[j]) x2 = r[j];
					if(y1 > c[j]) y1 = c[j];
					if(y2 < c[j]) y2 = c[j];
				}
			}
			if(num % 2 == 0) ans += x1 * y1 * (n - x2 + 1) * (m - y2 + 1);
			else ans -= x1 * y1 * (n - x2 + 1) * (m - y2 + 1);
		}
		printf("%lld\n", ans);
	}
}
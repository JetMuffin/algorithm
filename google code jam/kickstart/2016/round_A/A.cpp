#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
const LL mod = 1000000007;
LL inv_2 = 500000004;
LL inv_6 = 166666668;
int cas = 0;
int main() {
	int T;
	LL R, C;
	scanf("%d", &T);
	while(T--) {
		cas ++;
		scanf("%lld%lld", &R, &C);
		LL m = min(R, C) - 1;
		LL ans = 0;
		// for(int i = 1; i <= m - 1; i ++) {
		// 	ans = (ans + (R - i) * (C - i) * i % mod) % mod;
		// }
		LL single_sum = (m * (m + 1) % mod) * inv_2 % mod;
		LL double_sum = (((m * (m + 1) % mod) * (2 * m + 1) % mod) * inv_6 % mod);
		LL triple_sum = (single_sum * single_sum % mod);

		ans = (R * C % mod) * single_sum % mod;
		ans = (ans - (R + C) % mod * double_sum % mod + mod) % mod;
		ans = (ans + triple_sum) % mod;
		printf("Case #%d: %lld\n", cas, ans);
	}
}
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1000001;
double dp[maxn];
int nxt[maxn];
int p, q, n;
void pre() {
	nxt[0] = p;
	for(int i = 1; i <= n; i++) {
		nxt[i] = nxt[i - 1] / 2;
	}
}
void solve() {
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		int cnt = (100 - nxt[i-1]) / q;
		if(cnt * q == 100 - nxt[i-1]) cnt--;
		cnt++;
		// printf("i(%d) cnt(%d)\n", i, cnt);
		for(int j = 0; j <= cnt; j++) {
			double t = 1.0;
			double s = nxt[i-1] / 100.0;
			for(int k = 0; k < j; k++) {
				t *= (1 - s);
				// printf("i(%d) j(%d) k(%d) %lf\n", i, j, k, 1 - s);
				s += q / 100.0;
			}
			t *= s > 1 ? 1 : s;
			t *= j + 1;
			// printf("s(%lf) t(%lf)\n", s, t);
			dp[i] += t;
		}
	}
}
int main() {
	while(~scanf("%d%d%d", &p, &q, &n)) {
		memset(dp, 0, sizeof(dp));
		pre();
		solve();
		double ans = 0;
		for(int i = 0; i <= n; i++) {
			ans += dp[i];
		}
		printf("%.2lf\n", ans);
	} 
}
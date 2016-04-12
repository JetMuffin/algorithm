#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t, cas = 0, k, c, s, n, m;
	scanf("%d", &t);
	while(t--) {
		cas ++;
		scanf("%d%d%d",&k, &c, &s);
		n = k/c;
		if(n*c < k) n++;
		if(s < n) {
			printf("Case #%d: IMPOSSIBLE\n", cas);
			continue;
		}
		m = min(k, c);
		printf("Case #%d: ", cas);
		for(int i = 1; i <= k/c; i++) {
			long long ans = 1;
			for(int j = 1; j <= m; j++) {
				ans *= (m*(i-1)+j);
			}
			printf("%lld%c", ans, i*c==k? '\n': ' ');
		}
		if(k/c*c < k) {
			long long ans = 1;
			for(int i = k; i >= k-m+1; i--) {
				ans *= i;
			}
			printf("%lld\n", ans);
		}		
	}
}
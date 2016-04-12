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
		if(c*s < k) {
			printf("Case #%d: IMPOSSIBLE\n", cas);
			continue;
		}
		printf("Case #%d: ", cas);
		for(int i = 1; i <= k+1; i += c) {
			long long p = 1;
			for(int j = 1; j <= c; j++) {
				p = (p-1)*k + min(i+j,k);
			}
			printf("%lld%c", p, i==k+1? '\n': ' ');
		}
	}
}
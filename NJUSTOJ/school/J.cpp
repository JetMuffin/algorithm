#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define LL long long
using namespace std;
const int maxn = 100010;
int w[maxn];
int h[maxn];
int main() {
	int n;
	while(~scanf("%d", &n)) {
		if(n == 0) {
			puts("1");
			continue;
		}
		memset(w, 0, sizeof(w));
		memset(h, 0, sizeof(h));
		for(int i = 0 ; i < n; i++) {
			scanf("%d %d", &h[i], &w[i]);
		}
		int maxh = h[0];
		for(int i = 1; i < n; i++) {
			if(h[i] > maxh) {
				maxh = h[i];
			}
		}
		maxh ++;
		LL ans = 0;
		for(int i = 0; i < n ; i++) {
			ans += (maxh-h[i])*w[i];
		}
		printf("%lld\n", ans);
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1005;
int a[maxn], vis[maxn];
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	int n;
	while(~scanf("%d", &n)) {
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int res = 1;
		for(int i = 1; i <= n ; i++) {
			int cnt = 0;
			if(!vis[i]) {
				int p = i;
				while(!vis[p]) {
					vis[p] = 1;
					p = a[p];
					cnt++;
				}
				res = lcm(res, cnt);
			}
		}
		printf("%d\n", res);
	}
}
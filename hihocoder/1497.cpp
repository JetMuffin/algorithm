#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long
int main() {
	int n, x, y;
	while(~scanf("%d", &n)) {
		map<int, ll> m[4];
		for(int i = 0 ; i < n; i++) {
			scanf("%d%d", &x, &y);
			m[0][x]++;
			m[1][y]++;
			m[2][x-y]++;
			m[3][y+x]++;
		}
		ll ans = 0;
		ll k;
		for(int i = 0; i < 4; i++) {
			for(map<int, ll>::iterator it = m[i].begin(); it != m[i].end(); it++) {
				k = it->second;
				ans += k * (k - 1) / 2;
			}
		}
		printf("%lld\n", ans);
	}
}
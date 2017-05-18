#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define ll long long
#define INF 0xffffffff
int main() {
	ll n, q, ans, k, cnt;
	while(~scanf("%lld%lld", &n, &q)) {
		k = 1;
		cnt = 0;
		ans = INF;
		while(k < n) {
			ll t = n / k;
			if(n / k * k < n) t++;
			ans = min(t + cnt * q, ans);
			k *= 2;
			cnt ++;
		}
		printf("%lld\n", ans);
	}
}
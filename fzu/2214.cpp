#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 5100;
const ll inf = 1000000100;
ll w[maxn], v[maxn], dp[maxn];
int main() {
	int t, n;
	ll p;
	// scanf("%d", &t);
	cin>>t;
	while(t--) {
		// scanf("%d%lld", &n, &p);
		cin>>n>>p;

		ll sum = 0;
		for(int i = 0; i < n; i++) {
			// scanf("%lld%lld", &w[i], &v[i]);
			cin>>w[i]>>v[i];
			sum += v[i];
		}
		memset(dp , 0x3f3f3f3f , sizeof(dp));
		dp[0] = 0;
		for(int i = 0; i < n; i++) {
			for(int j = sum; j >= v[i]; j--) {
				dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
			}
		}

		for(int i = sum; i >= 0; i--) {
			if(dp[i] <= p) {
				// printf("%d\n", i);
				cout<<i<<endl;
				break;
			}
		}
	}
}
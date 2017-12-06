#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 21;
int dp[20000][maxn];
int g[maxn][maxn];
vector<int> state;
int n;
int cal(int state, int i) {
	int sum = 0, t = 0;
	while(state) {
		if(state & 1) {
			sum += g[i][t];
		}
		t++;
		state >>= 1;
	}
	return sum;
}
int main() {
	while(~scanf("%d", &n)) {
		memset(dp, 0, sizeof(dp));
		state.clear();
		for(int i = 0; i < n ; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d", &g[i][j]);
			}
		}
		for(int i = 0; i < (1<<n); i++) {
			if((i & (i<<1)) == 0)
				state.push_back(i);
		}
		int len = state.size();
		for(int i = 0; i < len; i++) {
			dp[i][0] = cal(state[i], 0);
		}
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < len; j++) {
				for(int k = 0; k < len; k++) {
					if(state[j] & state[k])
						continue;
					dp[j][i] = max(dp[j][i], dp[k][i-1] + cal(state[j], i));
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < len; i++) {
			ans = max(dp[i][n-1], ans);
		}
		printf("%d\n", ans);
	}
}
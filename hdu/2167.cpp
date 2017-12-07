#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;
const int maxn = 20;
char s[10000];
int g[maxn][maxn];
int sum[20000][maxn];
int dp[20000][maxn];
int state[20000];
int n, cnt;
void init() {
	memset(dp, 0, sizeof(dp));
	memset(state, 0, sizeof(state));
	memset(sum, 0, sizeof(sum));
	cnt = 0;
	for(int i = 0; i < (1<<n); i++) {
		if((i & (i<<1)) == 0)
			state[cnt++] = i;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < cnt; j++) {
			for(int k = 0; k < n; k++) {
				if((1<<k) & state[j]) {
					sum[j][i] += g[i][k];
				}
			}
		}
	}
}
int main() {
	while(gets(s)) {
		if(strlen(s) == 0) continue;
		stringstream ss(s);
		n = 0;
		while(ss >> g[0][n++]);
		n --;
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d", &g[i][j]);
			}
		}

		init();

		for(int i = 0; i < cnt; i++) {
			dp[i][0] = sum[i][0];
		}

		int sj, sk;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < cnt; j++) {
				for(int k = 0; k < cnt; k++) {
					sj = state[j];
					sk = state[k];
					if((sj&sk) || (sj & (sk<<1)) || ((sk>>1)&sj))
						continue;
					dp[j][i] = max(dp[j][i], dp[k][i-1]+sum[j][i]);
				}
			}
		}

		int ans = 0;
		for(int i = 0; i < cnt; i++) {
			ans = max(dp[i][n-1], ans);
		}
		printf("%d\n", ans);
	}
}
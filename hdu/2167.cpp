#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;
const int maxn = 20;
char s[10000];
int g[maxn][maxn];
int dp[20000][maxn];
vector<int> state;
int cal(int s, int i) {
	int sum = 0, t = 0;
	while(s) {
		if(s & 1) {
			sum += g[i][t];
		}
		t++;
		s >>= 1;
	}
	return sum;
}
int main() {
	int n = 0;
	memset(dp, 0, sizeof(dp));
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
		// for(int i = 0; i< n; i++) {
		// 	for(int j = 0; j< n;j++) {
		// 		printf("%d ", g[i][j]);
		// 	}
		// 	printf("\n");
		// }

		for(int i = 0; i < (1 << n); i++) {
			if((i & (i<<1)) == 0)
				state.push_back(i);
		}
		int m = state.size();

		for(int i = 0; i < m; i++) {
			dp[i][0] = cal(state[i], 0);
		}

		int sj, sk;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				for(int k = 0; k < m; k++) {
					sj = state[j];
					sk = state[k];
					if((sj&sk) || (sj & (sk<<1)) || ((sk>>1)&sj))
						continue;
					dp[j][i] = max(dp[j][i], dp[k][i-1]+cal(sj, i));
				}
			}
		}

		int ans = 0;
		for(int i = 0; i < m; i++) {
			ans = max(dp[i][n-1], ans);
		}
		printf("%d\n", ans);
	}
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 13;
vector<int> g[maxn];
int dp[1<<maxn][maxn];
int vis[maxn][maxn];
int n, m, u, v;
int ans;
int dfs(int state, int u) {
	// cout<<u<<" "<<state<<" "<<bitset<sizeof(int)*8>(state)<<endl;
	if (dp[state][u] != -1) {
		return dp[state][u];
	}

	int ret = 0;
	for(int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		int next_state = (1 << v) | state;
		if (((1 << v) & state) == 0) 
			ret += dfs(next_state, v);
	}

	return dp[state][u] = ret;
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
		memset(g, 0, sizeof(g));
		memset(dp, -1, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		ans = 0;
		for(int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			if(!vis[u-1][v-1]) {
				g[u-1].push_back(v-1);
				vis[u-1][v-1] = 1;			
			}
		}
		dp[(1<<n)-1][0] = 1;
		ans = dfs(0, 0);

		printf("%d\n", ans);
	}
}
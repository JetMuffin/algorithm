#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 6050;
int dp[maxn][2];
int fa[maxn];
vector<int> g[maxn];
void dfs(int u) {
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        dfs(v);
    }
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(dp, 0, sizeof(dp));
        memset(g, 0, sizeof(g));
        for(int i = 0; i < n; i++) {
            scanf("%d", &dp[i][1]);
        }
        int u, v;
        memset(fa, -1, sizeof(fa));
        while(~scanf("%d%d", &u, &v) && n && v) {
            g[v].push_back(u);
            fa[u] = v;
        }
        int root = 1;
        while(fa[root] != -1) root = fa[root];
        dfs(root);
        printf("%d\n", max(dp[root][1], dp[root][0]));
    }
}

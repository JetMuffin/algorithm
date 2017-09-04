#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> g[maxn];
int cnt[maxn],vis[maxn];
int ret;
void add_edge(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
}
void dfs(int r, int pre) {
    cnt[r] = 1;
    for(int i = 0; i < g[r].size(); i++) {
        int v = g[r][i];
        if(v == pre) continue;
        dfs(v, r);
        if (cnt[v] % 2 == 0) ret++;
        cnt[r] += cnt[v];
    }
}
int main() {
    int n, a, b;
    while(~scanf("%d", &n)) {
        memset(g, 0, sizeof(g));
        ret = 0;
        for(int i = 1; i <= n; i++) {
            cnt[i] = 1;
        }
        for(int i = 0; i < n - 1; i ++) {
            scanf("%d%d", &a, &b);
            add_edge(a, b);
        }
        dfs(1, 0);
        for(int i = 1; i <= n; i++) {
            printf("%d\n", cnt[i]);
        }
    }
}

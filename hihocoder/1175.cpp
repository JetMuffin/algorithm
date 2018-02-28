#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int mod = 142857;
vector<int> g[500005];
int a[500005], in[500005];
int n, m, k, u, v;
queue<int> q;
void bfs() {
    while(!q.empty()) {
        q.pop();
    }
    for(int i = 1; i <= n; i++) {
        if (in[i] == 0)
            q.push(i);
    }
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); i++) {
            v = g[u][i];
            in[v] --;
            a[v] = (a[v] + a[u]) % mod;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
}
int main() {
    while(~scanf("%d%d%d", &n, &m, &k)) {
        memset(a, 0, sizeof(a));
        memset(in, 0, sizeof(in));
        memset(g, 0, sizeof(g));
        for(int i = 0; i < k; i++) {
            scanf("%d", &u);
            a[u] = 1;
        }

        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            in[v]++;
        }
        bfs();

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = (ans + a[i]) % mod;
        }
        printf("%d\n", ans);
    }
}

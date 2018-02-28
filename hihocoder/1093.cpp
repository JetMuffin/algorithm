#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector <pair<int, int> > g[100010];
int dis[100010];
int vis[100010];
const int inf = 0x7fffffff;
int n, m, u, v, w, s, t;
void spfa() {
    for(int i = 1; i <= n; i++) {
        dis[i] = inf;
        vis[i] = 0;
    }

    queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;

    while(!q.empty()) {
        u = q.front();
        q.pop();
        vis[u] = 0;

        for (int i = 0; i < g[u].size(); i++) {
            v = g[u][i].first;
            w = g[u][i].second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
int main() {
    while(~scanf("%d%d%d%d", &n, &m, &s, &t)) {
        memset(g, 0, sizeof(g));
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            g[u].push_back(make_pair(v, w));
            g[v].push_back(make_pair(u, w));
        }
        spfa();
        printf("%d\n", dis[t]);
    }
}

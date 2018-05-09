#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 10010;
vector<pair<int,int> > g[maxn];
int vis[maxn];
int max_v, max_w;
struct node {
    int u, w;
    node(int a, int b): u(a), w(b) {}
};
void bfs(int s) {
    memset(vis, 0, sizeof(vis));
    queue<node> q;
    q.push(node(s, 0));
    vis[s] = 1;

    while(!q.empty()) {
        node cur = q.front();
        q.pop();

        if (g[cur.u].size() == 1) {
            if (cur.w > max_w) {
                max_w = cur.w;
                max_v = cur.u;
            }
        }

        for(int i = 0; i < g[cur.u].size(); i++) {
            int v = g[cur.u][i].first;
            int w = g[cur.u][i].second;
            if (!vis[v]) {
                q.push(node(v, cur.w + w));
                vis[v] = true;
            }
        }
    }
}

int main() {
    int u, v, w;
    int s = -1;
    while(~scanf("%d%d%d", &u, &v, &w)) {
        if (s == -1) s = u;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    bfs(s);
    bfs(max_v);
    printf("%d\n", max_w);
}

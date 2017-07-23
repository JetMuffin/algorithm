#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 40010;
struct Edge {
	int to, next, len;
}edge[maxn * 2];
int fa[maxn], ans[maxn], head[maxn], dis[maxn], cnt;
vector<int> query[maxn];
vector<int> num[maxn];
bool vis[maxn];
int n, q;
void init() {
	cnt = 0;
	for(int i = 1; i < maxn; i++) {
		head[i] = -1;
		fa[i] = i;
		ans[i] = 0;
		vis[i] = false;
		dis[i] = 0;
		query[i].clear();
		num[i].clear();
	}
}
void add_edge(int u, int v, int length) {
	edge[cnt].to = v;
	edge[cnt].len = length;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y) {
	fa[Find(y)] = Find(x);
}
void lca(int u) {
	vis[u] = true;

	for(int i = head[u]; i != -1; i = edge[i].next) {
		int v = edge[i].to;
		if(vis[v]) 
			continue;
		dis[v] = dis[u] + edge[i].len;
		lca(v);

		Union(u, v);
	}
	for(int i = 0; i < query[u].size(); i++) {
		int v = query[u][i];
		if(!vis[v])
			continue;
		ans[num[u][i]] = dis[u] + dis[v] - 2 * dis[Find(v)];
	}
}
int main() {
	int t, u, v, w;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &q);
		init();
		for(int i = 1; i < n; i++) {
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, w);
			add_edge(v, u, w);
		}
		for(int i = 0; i < q; i++) {
			scanf("%d%d", &u, &v);
			query[u].push_back(v);
			query[v].push_back(u);
			num[u].push_back(i);
			num[v].push_back(i);
		}
		lca(1);
		for(int i = 0; i < q; i++) {
			printf("%d\n", ans[i]);
		}
	}
}
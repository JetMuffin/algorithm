#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100010;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define root 1, n, 1
#define ll long long
const int INF = 0x3f3f3f3f;
ll ans[maxn<<2];
int lid[maxn], rid[maxn], idx[maxn];
int pre[maxn], w[maxn];
vector<int> g[maxn];
int cnt = 0;
void push_up(int rt) {
	ans[rt] = min(ans[rt<<1], ans[rt<<1|1]);
}
void build(int l, int r, int rt) {
	if(l == r) {
		ans[rt] = w[idx[l]];
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	push_up(rt);
}
void update(int p, int c, int l, int r, int rt) {
	if(l == r) {
		ans[rt] = c;
		return;
	}
	int m = (l + r) >> 1;
	if(p <= m) update(p, c, lson);
	else update(p, c, rson);
	push_up(rt);
}
int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return ans[rt];
	}
	int m = (l + r) >> 1;
	int ret = 1e9+10;
	if(L <= m) ret = min(ret, query(L, R, lson));
	if(m < R) ret = min(ret, query(L, R, rson));
	return ret;
}
int dfs(int u) {
	lid[u] = ++cnt;
	idx[cnt] = u;
	for(int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		dfs(v);
	}
	rid[u] = cnt;
}
int main() {
	int n, q, op, k, s;
	while(~scanf("%d", &n)) {
		cnt = 0;
		memset(g, 0, sizeof(g));
		for(int i = 1; i <= n; i++) {
			scanf("%d", &w[i]);
		}
		for(int i = 1; i <= n; i++) {
			pre[i] = -1;
		}
		for(int i = 2; i <= n; i++) {
			scanf("%d", &pre[i]);
			g[pre[i]].push_back(i);
		}

		dfs(1);
		build(root);
		scanf("%d", &q);
		for(int i = 0; i < q; i++) {
			scanf("%d", &op);
			if(op == 1) {
				scanf("%d%d", &k, &s);
				update(lid[k], s, root);
				// update(k, s);
			} else {
				scanf("%d", &k);
				// printf("%d\n", query(k));
				printf("%d\n", query(lid[k], rid[k], root));
			}
		}
	}
}
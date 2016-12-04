#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[100010];
int fa[100010];
struct node {
	int x, y;
	node(){}
	node(int a, int b) {
		x = a;
		y = b;
	}

	void print() {
		cout<<x<<" "<<y<<endl;
	}
}g[100010];
int find(int x)
{
    if(x != fa[x])
        fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int x,int y)
{
    int a = find(x),b = find(y);
    if(a != b){
        fa[b] = a;
        f[a] += f[b];
    }
}
bool cmp(node a, node b) {
	if(a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}
int main() {
	int t, n, m, a, b;
	scanf("%d", &t);
	while(t--) {
		memset(f, 0, sizeof(f));
		scanf("%d%d", &n, &m);
		long long ans = 0;
		for(int i = 1; i <= n; i++) {
			f[i] = i;
			fa[i] = i;
		}
		for(int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			g[i] = node(a, b);
		}
		sort(g, g+m, cmp);
		// for(int i = 0; i < m; i++){
		// 	g[i].print();
		// }
		for(int i = 0; i < m; i++) {
			if(find(g[i].x) < find(g[i].y))
				fa[g[i].y] = find(g[i].x);
		}
		// for(int i = 1 ; i <= n; i++) {
		// 	cout<<fa[i]<<endl;
		// }
		for(int i = 1; i <= n; i++) {
			// cout<<f[i]<<endl;
			ans += fa[i];
		}
		printf("%lld\n", ans);
	}
}
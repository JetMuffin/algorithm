#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1000;
struct node {
	int x, y, w;
	node(){}
	node(int a, int b, int c): x(a), y(b), w(c){}
};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
int g[maxn][maxn], dis[maxn][maxn], vis[maxn][maxn];
char s[maxn];
queue<node> q;
void print() {
	for(int i = 0; i < n; i++) {
		for(int j = 0 ; j < m ;j++) {
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
}
void bfs() {
	while(!q.empty()) {
		node cur = q.front();
		// printf("%d %d %d\n", cur.x, cur.y, cur.w);
		dis[cur.x][cur.y] = cur.w;
		q.pop();
		for(int k = 0; k < 4; k++) {
			int xx = cur.x + dx[k];
			int yy = cur.y + dy[k];
			int ww = cur.w + 1;
			if(!vis[xx][yy] && xx < n && yy < m && xx >= 0 && yy >= 0) {
				q.push(node(xx, yy, ww));
				vis[xx][yy] = 1;
			}
		}
	}
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
		memset(vis, 0, sizeof(vis));
		memset(dis, 0 , sizeof(dis));
		for(int i = 0; i <n ;i ++) {
			scanf("%s", s);
			for(int j = 0; j < m; j++) {
				g[i][j] = s[j] == '0' ? 0 : 1;
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(g[i][j] == 0) {
					q.push(node(i, j, 0));
					vis[i][j] = 1;
				}
			}
		}
		bfs();
		print();
	}
}
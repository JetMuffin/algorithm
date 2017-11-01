#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 55;
struct state {
	int x1, y1;
	int x2, y2;
	int step;
	state(int a, int b, int c, int d, int n):x1(a), y1(b), x2(c), y2(d), step(n) {}
	void print() {
		cout<<"("<<x1<<", "<<y1<<")"<<" ("<<x2<<", "<<y2<<") "<<step<<endl;
	}
};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int g[maxn][maxn];
int vis[maxn][maxn][maxn][maxn];
char s[maxn];
int n, m;
int bfs() {
	int x1, y1, x2, y2;
	queue<state> q;
	state start(0, 0, n-1, m-1, 0);
	vis[0][0][n-1][m-1] = 1;
	q.push(start);
	while(!q.empty()) {
		state cur = q.front();
		// cur.print();
		q.pop();
		if (cur.x1 == n-1 && cur.y1 == m-1 && cur.x2 == 0 && cur.y2 == 0) return cur.step;
		for(int i = 0; i < 2; i++) {
			x1 = cur.x1 + dx[i];
			y1 = cur.y1 + dy[i];
			x2 = cur.x2 + dx[2+i];
			y2 = cur.y2 + dy[2+i];
			x1 = (x1 >= n || y1 >= m || g[x1][y1] == 1) ? cur.x1 : x1;
			y1 = (x1 >= n || y1 >= m || g[x1][y1] == 1) ? cur.y1 : y1;
			x2 = (x2 < 0 || y2 < 0 || g[x2][y2] == 1) ? cur.x2 : x2;
			y2 = (x2 < 0 || y2 < 0 || g[x2][y2] == 1) ? cur.y2 : y2;
			if(vis[x1][y1][x2][y2] || (x1 == x2 && y1 == y2) || (x1 == cur.x2 && y1 == cur.y2 && x2 == cur.x1 && y2 == cur.y1)) continue;
			vis[x1][y1][x2][y2] = 1;
			q.push(state(x1, y1, x2, y2, cur.step+1));
		}
	}
	return -1;
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++) {
			scanf("%s", s);
			for(int j = 0; j < m; j++) {
				g[i][j] = s[j] - '0';
			}
		}
		printf("%d\n", bfs());
	}
}
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 550;
int g[maxn][maxn], vis[maxn][maxn], color[maxn][maxn];
int col;
char s[maxn];
struct node {
	int x, y;
	node() {}
	node(int a, int b): x(a), y(b) {}
};
vector<vector<node> > ans;
queue<node> q;
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void bfs(int x, int y) {
	node a = node(x, y);
	color[x][y] = col;
	q.push(a);
	while(!q.empty()) {
		node b = q.front();
		q.pop();
		int curx = b.x;
		int cury = b.y;
		vis[curx][cury] = 1;
		for(int k = 0; k < 4; k++) {
			int nextx = curx + dx[k];
			int nexty = cury + dy[k];
			if(g[nextx][nexty] == 1 && !vis[nextx][nexty]) {
				color[nextx][nexty] = col;
				ans[col-1].push_back(node(nextx, nexty));
				q.push(node(nextx, nexty));
			}
		}
	}
}
void work() {
	memset(vis, 0, sizeof(vis));
	memset(color, 0, sizeof(color));
	col = 0;
	for(int j = 0; j < n; j++) {
		for(int i = 0; i < m; i++) {
			if(g[i][j] == 1 && !vis[i][j]) {
				vector<node> com;
				com.push_back(node(i, j));
				ans.push_back(com);
				col++;
				bfs(i, j);
			}
		}
	}
}
void output(vector<node> com) {
	int minx = n - 1, miny = m - 1;
	int maxx = 0, maxy = 0;
	for(int i = 0; i < com.size(); i++) {
		if(com[i].x > maxx) maxx = com[i].x;
		if(com[i].y > maxy) maxy = com[i].y;
		if(com[i].x < minx) minx = com[i].x;
		if(com[i].y < miny) miny = com[i].y;
	}
	int c = color[com[0].x][com[0].y];
	cout<<maxx-minx+1<<" "<<maxy-miny+1<<endl;
	for(int i = minx; i <= maxx; i++) {
		for(int j = miny; j <= maxy; j++) {
			if(color[i][j] == c)
				cout<<g[i][j];
			else
				cout<<0;
		}
		cout<<endl;
	}
}

void debug() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout<<color[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i = 0; i < ans.size(); i++) {
		cout<<ans[i][0].x<<" "<<ans[i][0].y<<endl;
	}
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
		memset(g, 0, sizeof(g));
		ans.clear();
		for(int i = 0 ; i < n; i++) {
			scanf("%s", s);
			for(int j = 0; j < m; j++) {
				g[i][j] = s[j] - '0';
			}
		}
		work();
		// debug();
		for(int i = 0; i < ans.size(); i++) {
			output(ans[i]);
		}
	}
}
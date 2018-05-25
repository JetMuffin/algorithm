#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[105][105];
bool vis[105][105];
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int n, m;
void dfs(int x, int y) {
    int xx, yy;
    for(int i = 0; i < 8; i++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && s[xx][yy] == 'W' && !vis[xx][yy]) {
            vis[xx][yy] = true;
            dfs(xx, yy);
        }
    }
}
int main() {
    while(~scanf("%d%d", &n, &m)) {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            scanf("%s", s[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (s[i][j] == 'W' && !vis[i][j]) {
                    ans ++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
}

class Solution {
public:
    bool vis[105][105];
    int ans = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    void dfs(int x, int y, vector<vector<int>>& grid) {
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx == -1 || xx == grid.size() || yy == -1 || yy == grid[0].size()) {
                ans++;
            } else if(grid[xx][yy] == 1) {
                if(!vis[xx][yy]) {
                    dfs(xx, yy, grid);
                }
            } else {
                ans ++;
            }
        }
        cout<<ans<<endl;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};
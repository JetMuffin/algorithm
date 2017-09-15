class Solution {
public:
    int dp[105][105];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, 0, sizeof(dp));
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        for(int i = 0; i < n && obstacleGrid[i][0]!=1; i++) {
            dp[i][0] = 1;
        }
        for(int j = 0; j < m && obstacleGrid[0][j]!=1; j++) {
            dp[0][j] = 1;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
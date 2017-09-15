class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        long long bound = INT32_MAX;
        int x = 1;
        for(int i = n; i <= m+n-2; i++) {
            ans *= i;
            while(ans > INT32_MAX) {
                ans /= x;
                x++;
            }
        }
        for(int i = x; i <= m-1; i++) {
            ans /= i;
        }
        return ans;
    }
};
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0, ans = 0;
        while(n > 0) {
            i++;
            ans++;
            n -= i;
        }
        if(n < 0) ans--;
        return ans;
    }
};

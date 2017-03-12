#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution  {
public:
    int dp[1010][1010];
    string shortestPalindrome(string s) {
        int len = s.length();
        string t = string(s.rbegin(), s.rend());
        memset(dp, 0, sizeof(dp));
        int res = 0, index = 0;
        for(int i = 0 ; i < len; i++) {
            for(int j = 0 ; j < len; j++) {
                if(s[i] == t[j]) {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    if(dp[i][j] > res) {
                        res = dp[i][j];
                        index = i + 1 - res;
                    }
                }
            }
        }
        return t + s.substr(index + res, s.length() - 1);
    }
};
int main() {
    string s;
    while(cin>>s) {
        Solution so;
        cout<<so.shortestPalindrome(s)<<endl;
    }
}

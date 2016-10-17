#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
    int c[58];
    public:
        int longestPalindrome(string s) {
            memset(c, 0, sizeof(c));
            int tot = 0;
            for(int i = 0 ; i < s.length(); i++){
                if(c[s[i]-'A']++ == 0) {
                    tot++;
                }
            }
            bool odd = true;
            int res = 0;
            for(int i = 0; i < 58; i++) {
                if (c[i] & 1) {
                    res += c[i] - 1;
                    c[i] = 1;
                } else {
                    res += c[i];
                    c[i] = 0;
                }
            }
            for(int i = 0; i < 58; i++) {
                if(c[i] == 1) {
                    res ++;
                    break;
                }
            }
            return res;
        }
};
int main() {
    Solution s;
    string ss;
    while(cin>>ss) {
        cout<<s.longestPalindrome(ss)<<endl;
    }
}

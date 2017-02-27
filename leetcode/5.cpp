#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    int p[2002];
    string longestPalindrome(string s) {
        string t = "#";
        for(int i = 0; i < s.length(); i++) {
            t = t + s[i] + '#';
        }
        memset(p, 0, sizeof(p));
        int c = 0, r = 0, i = 0;
        for(int i = 0; i < t.length(); i++) {
            if(r > i) p[i] = min(r - i, p[2 * c - i]);
            else p[i] = 0;
            while(i + p[i] < t.length() && i - p[i] >= 0 && t[i + p[i]] == t[i - p[i]]) p[i] ++;
            if(p[i] > r) {
                r = p[i];
                c = i;
            }
        }
        t = t.substr(c - r + 1, 2 * r - 1);
        string res;
        for(int i = 0; i < t.length(); i++) {
            if(t[i] != '#') res += t[i];
        }
        return res;
    }
};
int main() {
    Solution s;
    string str;
    while(cin>>str) {
        cout<<s.longestPalindrome(str)<<endl;
    }
}
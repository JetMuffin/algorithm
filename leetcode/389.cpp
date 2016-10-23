#include <iostream>
#include <cstring>
using namespace std;
class Solution {
    public:
        char b[26];
        char findTheDifference(string s, string t) {
            memset(b, 0, sizeof(b));
            for(int i = 0; i < t.length(); i++) {
                b[t[i]-'a']++;
            }
            for(int i = 0; i < s.length(); i++) {
                b[s[i]-'a']--;
            }
            for(int i = 0 ; i < 26; i++) {
                if(b[i]) {
                    return 'a' + i;
                }
            }
            return 'a';
        }
};
int main() {
    Solution s;
    cout<<s.findTheDifference("abcd", "dcbae")<<endl;
}

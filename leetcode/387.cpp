#include <iostream>
#include <cstring>
using namespace std;

class Solution{
    int c[26];
    public:
        int firstUniqChar(string s) {
            memset(c, 0, sizeof(c));
            for(int i = 0; i < s.length(); i++) {
                c[s[i]-'a'] ++;
            }
            for(int i = 0; i < s.length(); i++) {
                if(c[s[i] - 'a'] == 1) {
                    return i;
                }
            }
            return -1;
        }
};

int main() {
    string s;
    Solution ss;
    while(cin>>s) {
        cout<<ss.firstUniqChar(s)<<endl;
    }
}

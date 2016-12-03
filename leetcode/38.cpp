#include <iostream>
using namespace std;
class Solution {
    public:
    string countAndSay(int n) {
        string s = "1";
        string next = "1";
        n--;
        while(n--) {
            next = "";
            for(int i = 0; i < s.length(); i++) {
                char c = s[i];
                int count = 1;
                while(s[i+1] == s[i]) {
                    count++;
                    i++;
                }
                next += '0' + count;
                next += c;
            }
            s = next;
        }
        return next;
    }
};
int main() {
    Solution s;
    int n;
    while(~scanf("%d", &n)) {
        cout<<s.countAndSay(n)<<endl;
    }
}

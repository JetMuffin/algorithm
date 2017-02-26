#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        while(s[i] == ' ' && i >= 0) i--;
        int end = i;
        while(s[i] != ' ' && i >= 0) i--;
        int start = i;
        return end - start;
    }
};
int main() {
    Solution s;
    string str;
    cout<<s.lengthOfLastWord("str weq  ")<<endl;
}
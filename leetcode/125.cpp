#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>
using namespace std;
class Solution {
public:
    char to_lower(char c) {
        if(c >= 'A' && c <= 'Z') return char(c+32);
        else return c;
    }
    bool valid(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c<= '9');
    }
    bool isPalindrome(string s) {
        int n = s.length() - 1;
        for(int i = 0, j = n; i <= j; i++, j--) {
            while(!valid(s[i])) i++;
            while(!valid(s[j])) j--;
            if(i<=j && to_lower(s[i])!=to_lower(s[j])) return false;
        }
        return true;
    }
};
int main() {
    Solution s;
    string str = "0 P";
    cout<<s.isPalindrome(str)<<endl;
}


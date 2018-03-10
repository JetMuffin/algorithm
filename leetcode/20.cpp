#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;
class Solution {
    public:
    bool left(char c) {
        return c == '(' || c == '{' || c == '[';
    }
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(left(s[i])) {
                st.push(s[i]);
            } else {
                if(st.empty()) {
                    return false;
                } else {
                    char c = st.top();
                    st.pop();
                    if(s[i] == ')' && c != '(') return false;
                    if(s[i] == ']' && c != '[') return false;
                    if(s[i] == '}' && c != '{') return false;

                }
            }
        }
        if(!st.empty()) {
            return false;
        }
        return true;
    }
};
int main() {
    string s;
    Solution so;
    while(cin>>s) {
        cout<<so.isValid(s)<<endl;
    }
}

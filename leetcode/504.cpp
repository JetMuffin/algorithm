#include <iostream>
#include <cstring>
using namespace std;
class Solution {
    public:
        string convertToBase7(int num) {
             if(num==0) return "0";
             string ans = "";
             int t;
             bool flag = num < 0;
             if(flag) num = -num;
             while(num) {
                ans = char('0' + num - num/7*7) + ans;
                num /= 7;
             }
             if(flag) ans = "-" + ans;
             return ans;
        }
};
int main() {
    int n;
    Solution s;
    while(cin>>n) {
        cout<<s.convertToBase7(n)<<endl;
    }
}

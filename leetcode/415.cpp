#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Solution {
    public:
        string addStrings(string num1, string num2) {
            string res = "";
            string curs;
            int add = 0;

            int total = max(num1.length(), num2.length()) + 1;
            while(num1.length() < total) num1 = "0" + num1;
            while(num2.length() < total) num2 = "0" + num2;
            for(int i = 0; i < total; i++) {
                int cur = num1[total-1-i] - '0' + num2[total-1-i] - '0' + add;
                add = cur / 10;
                cur = cur % 10;
                stringstream ss;
                ss << cur;
                ss >> curs;
                res = curs + res;
            }
            if(res[0] == '0') res = res.substr(1, total-1);
            return res;
        }
};

int main() {
    Solution s;
    string a, b;
    while(cin>>a>>b) {
        cout<<s.addStrings(a, b)<<endl;
    }
}

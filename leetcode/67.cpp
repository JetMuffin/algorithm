#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len = max(a.length(), b.length()) + 1;
        while(a.length() < len) a = "0" + a;
        while(b.length() < len) b= "0" + b;
        int add = 0, sum = 0;
        for(int i = len - 1; i >= 0; i--) {
            sum = (b[i] - '0') + (a[i] - '0') + add;
            if(sum >= 2) {
                add = 1;
                sum -= 2;
            } else {
                add = 0;
            }
            a[i] = sum == 0 ? '0' : '1';
        }
        if(a[0] == '0') {
            a = a.substr(1, a.length() - 1);
        }
        return a;
    }
};

int main() {
    Solution s;
    cout<<s.addBinary("11101", "1011")<<endl;
}
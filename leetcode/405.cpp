#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        char c[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        int b[32], index = 0, n;
        string res = "";
        memset(b, 0, sizeof(b));
        bool neg = num < 0;
        while(num) {
        	b[index] = neg ? (-num % 2) : num % 2;
        	num /= 2;
        	index ++;
        }

        // negative
        if (neg) {
            for(int i = 0; i < 32; i++) {
                b[i] = b[i] ? 0 : 1;
            }
            b[0] += 1;
            int o = 0, t;
            for(int i = 0; i < 32; i++) {
                t = b[i];
                b[i] = (b[i] + o) % 2;
                o = (t + o) / 2;
            }
        }

        for(int i = 0; i < 8; i++) {
            n = b[4 * i] * 1 + b[4 * i + 1] * 2 + b[4 * i + 2] * 4 + b[4 * i + 3] * 8;
            res = c[n] + res;
        }

        for(index = 0; index < res.length() && res[index] == '0'; index++);
        res = res.substr(index);
        return res;
    }
};
int main() {
	Solution s;
    int n;
    while(~scanf("%d", &n)) {
        cout<<s.toHex(n)<<endl;
    }
}
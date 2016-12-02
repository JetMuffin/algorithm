#include <iostream>
using namespace std;
class Solution {
    public:
    int findNthDigit(int n) {
        long b = 1, k = 1;
        long x = (long)n;
        while(x > 0) {
            x -= 9 * b * k;
            b *= 10;
            k ++;
        }
        b /= 10;
        k --;
        x += 9 * k * b;
        long t = b + (x - 1) / k;
        long j = (x - 1) % k + 1;
        for(int i = 0; i < j - 1; i++) {
            t = t % b;
            b /= 10;
        }
        long res = t / b;
        return res;
    }
};
int main() {
    Solution s;
    int n;
    while(~scanf("%d", &n)) {
        cout<<s.findNthDigit(n)<<endl;
    }
}

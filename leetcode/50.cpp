#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        bool neg = false;
        long t = n;
        if(t < 0) {
            t = -t;
            neg = true;
        }
        while(t > 0) {
            if(t & 1) {
                res *= x;
            }
            x = x * x;
            t >>= 1;
        }
        if(neg) res = 1 / res;
        return res;
    }
};
int main() {
    Solution s;
    double d;
    int n;
    while(cin>>d>>n) {
        cout<<s.myPow(d, n)<<endl;        
    }
}
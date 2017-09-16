#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    	if (m == n) return m;
        long long b = 1;
        while(b < n) b <<= 1;
        if(b != n) b = (int) (b >>= 1);
        int l = b;
        int x = 0;
        while(l) {
            // cout<<b<<" "<<l<<endl;
            if((b&n) != (b&m)) break;
            // cout<<(b&n) << " "<<(b&m)<<endl;
            x = b & n;
            l >>= 1;
            b += l;
        }
        return x;
    }
};
int main() {
	int x, y;
	Solution s;
	while(~scanf("%d%d", &x, &y)) {
		cout<<s.rangeBitwiseAnd(x, y)<<endl;
	}
}	
#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int c = x ^ y;
        int ans = 0;
        while(c) {
        	ans++;
        	c &= (c-1);
        }
        return ans;
    }
};
int main() {
	int x, y;
	Solution s;
	while(~scanf("%d%d", &x, &y)) {
		cout<<s.hammingDistance(x, y) << endl;
	}
}
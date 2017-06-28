#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
		vector<int> ret(num+1, 0);
		int b = 1;
		for(int i = 1; i < num + 1; i++) {
			if(i == b * 2) {
				b = i;
			}
			ret[i] = 1 + ret[i - b];
		}
		return ret;
    }
};

int main() {
	Solution s;
	int n;
	scanf("%d", &n);
	vector<int> ans = s.countBits(n);
	for(int i = 0; i < n; i++) {
		printf("%d: %d %d\n", i, __builtin_popcount(i), ans[i]);
	}
}
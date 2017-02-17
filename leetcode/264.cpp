#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
		int dp[1690];
		int j = 1, k = 1, l = 1;
    	dp[1] = 1;
    	for(int i = 2; i <= n; i++) {
    		dp[i] = min(2 * dp[j], min(3 * dp[k], 5 * dp[l]));
    		if(dp[i] == 2 * dp[j]) j++;
    		if(dp[i] == 3 * dp[k]) k++;
    		if(dp[i] == 5 * dp[l]) l++;
    	}
    	return dp[n];
    }
};
int main() {
	Solution s;
	int n;
	while(cin>>n) {
		cout<<s.nthUglyNumber(n)<<endl;
	}
}
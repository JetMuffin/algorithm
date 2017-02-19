#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size() == 0) {
    		return 0;
    	}
        int res = 0;
        for(int i = 0; i < prices.size() - 1; i++) {
            int increase =  prices[i+1] - prices[i];
            res += increase > 0 ? increase : 0;
        }
        return res;
    }
};
int main() {
	Solution s;
	int n;
	while(cin>>n) {
		vector<int> prices;
		for(int i = 0; i < n; i++) {
			int t;
			cin>>t;
			prices.push_back(t);
		}
		int ans = s.maxProfit(prices);
		cout<<ans<<endl;
	}
}
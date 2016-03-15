#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
		map<int, int> m;
		for(int i = 0; i < numbers.size(); ++ i)
		{
			if(m.find(target - numbers[i]) != m.end())
			{
				ans.push_back(m[target - numbers[i]] + 1);
				ans.push_back(i + 1);
				break;
			}
			m[numbers[i]] = i;
		}
		return ans;
    }
};
int main() {
	int n, m;
	Solution test;
	vector<int> nums;
	while(cin>>n) {
		nums.clear();
		for(int i = 0 ; i < n; i++) {
			int t;
			cin>>t;
			nums.push_back(t);
		}
		cin>>m;
		vector<int> ans = test.twoSum(nums, m);
		for(int i = 0; i < ans.size(); i++) {
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}
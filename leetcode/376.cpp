#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        int pre = nums[0], ret = 1, flag = -1;
        for(int i = 0; i < nums.size(); ++i) {  
            if(nums[i] == pre) continue;  
            if(flag != nums[i] > pre) {  
                flag = nums[i] > pre;  
                ++ret;  
            }  
            pre = nums[i];  
        }  
        return ret;
    }
};
int main() {
	Solution s;
	int n;
	vector<int> nums;
	while(~scanf("%d", &n)) {
		nums.clear();
		for(int i = 0 ; i < n; i++) {
			int t;
			scanf("%d", &t);
			nums.push_back(t);
		}
		cout<<s.wiggleMaxLength(nums)<<endl;
	}
}
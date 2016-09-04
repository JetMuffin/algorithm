#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int count = 0, now = 0;
        for(int i = 0 ; i < nums.size(); i++) {
        	if(count == 0) {
        		now = nums[i];
        		count = 1;
        	} else {
        		if(now == nums[i]) {
        			count ++;
        		} else {
        			count --;
        		}
        	}
        }
        return now;
    }
};
int main() {
	int n, t;
	vector<int> nums;
	while(~scanf("%d", &n)) {
		nums.clear();
		for(int i = 0; i < n; i++) {
			scanf("%d", &t);
			nums.push_back(t);
		}
		Solution s;
		cout<<s.majorityElement(nums)<<endl;
	}
}
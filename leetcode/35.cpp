#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, h = len - 1;
        int m;
        while(l < h) {
        	m = (l + h) / 2;
        	if(nums[m] > target) {
        		h = m - 1;
        	} else if(nums[m] < target) {
        		l = m + 1;
        	} else {
        		return m;
        	}
        }
        return nums[l] < target ? l + 1 : l;
    }
};
int main() {
	Solution s;
	int a[4] = {1, 3, 5, 6};
	vector<int> v;
	for(int i = 0; i < 4; i++) {
		v.push_back(a[i]);
	}
	cout<<s.searchInsert(v, 7)<<endl;
}
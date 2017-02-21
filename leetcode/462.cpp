class Solution {
public:
    int minMoves2(vector<int>& nums) {
		int sum = 0;
		sort(nums.begin(), nums.end());
		int i, j;
		for(i = 0, j = nums.size()-1; i < nums.size(), j < nums.size(), i < j; i++, j--) {
		    sum += (nums[j] - nums[i]);
		}
		return sum;
    }
};
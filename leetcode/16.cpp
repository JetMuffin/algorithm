class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mindiff = INT32_MAX;
        int len = nums.size();
        int ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < len - 2; i++) {
            int j = i + 1;
            int k = len - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                if(diff < mindiff) {
                    mindiff = diff;
                    ans = sum;
                }
                if(sum < target) {
                    j++;
                }else if(sum > target) {
                    k--;
                }else {
                    return sum;
                }
            }
        }
        return ans;
    }
};
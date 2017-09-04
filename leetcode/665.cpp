class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len == 1) return true;
        int cnt = 0;
        for(int i = 1; i < len; i++) {
            if(nums[i-1] > nums[i]) {
                cnt++;
                if(cnt > 1) return false;
                if(i < 2 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }
        return true;
    }
};

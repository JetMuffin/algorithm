class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = -1001, b = -1001, c = -1001, d = 1001, f = 1001;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > a) {
                c = b;
                b = a;
                a = nums[i];
            } else if(nums[i] > b) {
                c = b;
                b = nums[i];
            } else if(nums[i] > c) {
                c = nums[i];
            }
            if(nums[i] < d) {
                f = d;
                d = nums[i];
            } else if(nums[i] < f) {
                f = nums[i];
            }
        }
        return max(a*b*c, d*f*a);
    }
};
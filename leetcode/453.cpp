#include <iostream>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = 0x7fffffff;
        int res = 0;
        for(int i = 0 ; i < nums.size(); i++) {
        	if(nums[i] < min) min = nums[i];
        }

        for(int i = 0 ; i < nums.size(); i++) {
        	res += (nums[i] - min);
        }
        return res;
    }
};

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int size = nums.size();
        int idx = 0;
        for(int i = 0; i < size; i++) {
            if(nums[i]) {
                nums[idx ++] = nums[i];
            }
        }
        for(int i = idx; i < size; i++) {
            nums[i] = 0;
        }
    }
};

int a[5] = {0, 1, 0, 3, 2};
int main() {
	vector<int> nums;
	for(int i = 0 ; i <5 ; i++) {
        nums.push_back(a[i]);
    }
    Solution s;
	s.moveZeroes(nums);
	for(int i = 0 ; i < nums.size(); i++) {
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		vector<int> res;
		int size = nums.size();
		int count = 0;
		for(int i = 0; i < size; i++) {
			if(nums[i] != 0) 
				res.push_back(nums[i]);
			else
				count++;
		}        
		for(int i = 0 ; i < count; i++) {
			res.push_back(0);
		}
    }
};

int main() {
	int n, t;
	cin>>n;
	vector<int> nums;
	for(int i = 0 ; i < n; i++) {
		cin>>t;
		nums.push_back(t);
	}
	Solution test;
	test.moveZeroes(nums);
	for(int i = 0 ; i < nums.size(); i++) {
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}
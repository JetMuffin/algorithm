#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class NumArray {
private:
	int prefix[100000];
public:
    NumArray(vector<int> &nums) {
    	memset(prefix, 0, sizeof(prefix));
    	int size = nums.size();
    	if(!size) {
    		return;
    	}
    	for(int i = 0; i < size; i++) {
    		prefix[i+1] = prefix[i] + nums[i];
    	}
    }

    int sumRange(int i, int j) {
		return prefix[j+1] - prefix[i];    	
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main () {
	int n, m;
	while(cin>>n) {
		vector<int> nums;
		int t;
		for(int i = 0; i < n; i ++) {
			cin>>t;
			nums.push_back(t);
		}
		NumArray numArray(nums);
		cin>>m;
		int l,r;
		for(int i = 0; i < m; i++) {
			cin>>l>>r;
			cout<<numArray.sumRange(l, r)<<endl;
		}
	}
}

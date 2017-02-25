#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NumArray {
public:
	int tree[100010];
	vector<int> list;
	int size;
    NumArray(vector<int> nums) {
    	list = nums;
    	size = nums.size();
        memset(tree, 0, sizeof(tree));
        for(int i = 1 ; i <= size; i++) {
        	insert(i, nums[i - 1]);
        }
    }

	int lowbit(int x) {
		return x & (-x);
	}   

	void insert(int i, int val) {
		while(i <= 100000) {
			tree[i] += val;
			i += lowbit(i);
		}
	}

    void update(int i, int val) {
    	int t = i + 1;
    	int add = val - list[t - 1];
    	list[t - 1] = val;
        while(t <= 100000) {
        	tree[t] += add;
        	t += lowbit(t);
        }
    }
    
    int sum(int i) {
    	int sum = 0;
    	while(i > 0) {
    		sum += tree[i];
    		i -= lowbit(i);
    	}
    	return sum;
    }

    int sumRange(int i, int j) {
        if(i > j) {
        	int t = i;
        	i = j;
        	j = t;
        }
        return sum(j + 1) - sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

 int main() {
 	int n;
 	vector<int> input;
 	while(cin>>n) {
 		for(int i = 0 ; i < n; i++) {
 			int t;
 			cin>>t;
 			input.push_back(t);
 		}
 		NumArray *obj = new NumArray(input);
 		obj->update(0, 3);
 		cout<<obj->sumRange(1, 1)<<endl;
 		cout<<obj->sumRange(0, 1)<<endl;
 		obj->update(1, -3);
 		cout<<obj->sumRange(0, 1)<<endl;
 	}
 }
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
        	if(m[nums[i]]) {
        		return true;
        	} else {
        		m[nums[i]] ++;
        	}
        }
        return false;
    }
};
int main() {
	Solution s;

}
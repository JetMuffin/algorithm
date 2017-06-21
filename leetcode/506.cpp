#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
bool cmp(const int &a,const int &b) {
    return a > b;
}
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> copy;
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) copy.push_back(nums[i]);
        sort(copy.begin(), copy.end(), cmp);
        for(int i = 0; i < copy.size(); i++) m[copy[i]] = i+1;
        
        int rank;
        vector<string> ret;
        for(int i = 0; i < nums.size(); i++) {
            rank = m[nums[i]];
            if(rank == 1) {
                ret.push_back("Gold Medal");
            } else if(rank == 2) {
                ret.push_back("Silver Medal");
            } else if(rank == 3) {
                ret.push_back("Bronze Medal");
            } else {
                stringstream stream;
                stream<<rank;
                ret.push_back(stream.str());
            }
        }
        return ret;
    }
};

int main() {
	vector<int> nums;
	int n;
	scanf("%d", &n);
	int t;
	for(int i = 0; i < n; i++) {
		scanf("%d", &t);
		nums.push_back(t);
	}
	Solution s;
	vector<string> ans = s.findRelativeRanks(nums);
	for(int i = 0; i < ans.size(); i++) {
		cout<<ans[i]<<endl;
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
    public:
    vector<vector<int> > subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > ret;
        for(int i = 0; i < (int) 1<<n; i++) {
            vector<int> sub;
            for(int j = 0; j < n; j++) {
                if(i & (1<<j)) {
                    sub.push_back(nums[j]);
                }
            }
            ret.push_back(sub);
        }
        return ret;
    }
};
int main() {
    int n, t;
    cin>>n;
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        nums.push_back(t);
    }
    Solution s;
    s.subsets(nums);
}

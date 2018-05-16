#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int stack[100000];
        int lengthOfLIS(vector<int>& nums) {
            int len = nums.size();
            if(len == 0) return 0;
            int cnt = 0, l, r, m;
            stack[cnt++] = nums[0];
            for(int i = 1; i < len; i++) {
                l = 0, r = cnt - 1;
                while(l <= r) {
                    m = (l + r) / 2;
                    if(stack[m] > nums[i]) {
                        r = m - 1;
                    } else if (stack[m] < nums[i]) {
                        l = m + 1;
                    } else {
                        break;
                    }
                }
                if (stack[m] == nums[i]) continue;
                if (l >= 0 && l <= cnt) {
                }
                if (l < cnt) {
                    stack[l] = nums[i];
                } else {
                    stack[cnt++] = nums[i];
                }
            }
            return cnt;
        }
};
int main() {
    int n;
    Solution s;
    vector<int> nums;
    int t;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &t);
            nums.push_back(t);
        }
        printf("%d\n", s.lengthOfLIS(nums));
    }
}

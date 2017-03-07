#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
    struct node {
        int val, i;
        node() {}
        node(int v, int i): val(v), i(i) {}
    }buf[10000];
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size() == 0) return ans;
        int head = 0, tail = 0, idx = 0;
        buf[0] = node(nums[0], 0);
        for(int i = 1; i < nums.size(); i++) {
            if(i >= k) {
                ans.push_back(buf[head].val);
            }
            if(i - buf[head].i >= k) head++;
            while(buf[tail].val < nums[i] && tail >= head) tail--;
            buf[++tail] = node(nums[i], i);
        }
        ans.push_back(buf[head].val);
        return ans;
    }
};
int main() {
    int n, k;
    vector<int> nums;
    while(~scanf("%d%d", &n, &k)) {
        nums.clear();
        for(int i = 0; i < n; i++) {
            int t;
            scanf("%d", &t);
            nums.push_back(t);
        }
        Solution s;
        vector<int> ans = s.maxSlidingWindow(nums, k);
        for(int i = 0; i < ans.size(); i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}

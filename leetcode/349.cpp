#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                i++;
            } else if(nums1[i] > nums2[j]) {
                j++;
            } else {
                ans.push_back(nums1[i]);
                while(nums1[i] == nums2[j]) i++;
                j++;
            }
        }
        return ans;
    }
};

int main() {
	vector<int> nums1, nums2;
	int n, m, t;
	cin>>n>>m;
	for(int i = 0; i < n; i++) {
		cin>>t;
		nums1.push_back(t);
	}
	for(int j = 0; j < m; j++) {
		cin>>t;
		nums2.push_back(t);
	}
	Solution s;
	vector<int> ans = s.intersection(nums1, nums2);
	for(int i = 0 ; i < ans.size(); i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
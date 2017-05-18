class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> ma;
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++) ma[nums1[i]]++;
        for(int i = 0; i < nums2.size(); i++) {
            if(ma[nums2[i]]) {
                res.push_back(nums2[i]);
                ma[nums2[i]]--;
            }
        }
        return res;
    }
};

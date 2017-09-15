class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> res;
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = idx - 1, j = idx;
        while(!(i < 0 && j >= arr.size()) && res.size() < k) {
            if(i >= 0) {
                if (j < arr.size()) {
                    if(x - arr[i] <= arr[j] - x) {
                        res.push_front(arr[i]);
                        i--;
                    } else {
                        res.push_back(arr[j]);
                        j++; 
                    }
                } else {
                    res.push_front(arr[i]);
                    i--;
                }
            } else {
                res.push_back(arr[j]);
                j++; 
            }
        }
        
        
        vector<int> ans(res.begin(), res.end());
        
        return ans;
    }
};
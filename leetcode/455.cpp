bool cmp(const int &a,const int &b) {
    return a > b;
}
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), cmp);
        sort(s.begin(), s.end(), cmp);
        
        int i = 0, j = 0;
        for(; i < g.size() && j < s.size(); i++) {
            if(g[i] <= s[j]) j++; 
        }
        return j;
    }
};
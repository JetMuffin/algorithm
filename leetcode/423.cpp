class Solution {
public:
    string originalDigits(string s) {
        int cnt[26] = {0};
        vector<int> ans(10, 0);
        for(int i = 0; i < s.length(); i++) {
            cnt[s[i] - 'a']++;
        }
        ans[4] = cnt['u' - 'a'];
        ans[6] = cnt['x' - 'a'];
        ans[2] = cnt['w' - 'a'];
        ans[0] = cnt['z' - 'a'];
        ans[5] = cnt['f' - 'a'] - ans[4];
        ans[8]= cnt['g' - 'a'];
        ans[7] = cnt['s' - 'a'] - ans[6];
        ans[9] = cnt['i' - 'a'] - ans[6] - ans[5] - ans[8];
        ans[3] = cnt['h' - 'a'] - ans[8];
        ans[1] = cnt['o' - 'a'] - ans[2] - ans[4] - ans[0];
        string ret;
        for(int i = 0; i <= 9; i++) {
            for(int j = 0; j < ans[i]; j++) {
                ret += ('0' + i);
            }
        }
        return ret;
    }
};
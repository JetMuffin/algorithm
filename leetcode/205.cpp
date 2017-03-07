class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<int, int> dict;
        vector<int> pattern;
        int cnt = 1;
        for(int i = 0; i < s.length(); i++) {
            int c = s[i] - 'a';
            if(dict[c] == 0) dict[c] = cnt++;
            pattern.push_back(dict[c]);
        }
        cnt = 1;
        dict.clear();
        for(int i = 0; i < t.length(); i++) {
            int c = t[i] - 'a';
            if(dict[c] == 0) dict[c] = cnt++;  
            if(dict[c] != pattern[i]) return false;
        }
        return true;
    }
};

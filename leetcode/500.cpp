class Solution {
public:
    int alpha[26] = {1, 0, 0, 1, 2, 1, 1, 1, 2, 1, 1, 1, 0, 0, 2, 2, 2, 2, 1, 2, 2, 0, 2, 0, 2, 0};
    int convert(char c) {
        if(c >= 'A' && c <= 'Z') {
            return alpha[c - 'A'];
        } else if(c >= 'a' && c <= 'z') {
            return alpha[c - 'a'];
        } else {
            return -1;
        }
    }
    bool valid(string s) {
        int flag = convert(s[0]);
        for(int i = 0; i < s.length(); i++) {
            if(convert(s[i]) != flag) {
                return false;
            }
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for(int i = 0; i < words.size(); i++) {
            if(valid(words[i]))
                res.push_back(words[i]);
        }
        return res;
    }
};
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
	int r[26], m[26];
    bool canConstruct(string ransomNote, string magazine) {
    	memset(r, 0, sizeof(r));
    	memset(m, 0, sizeof(m));
    	for(int i = 0 ; i < ransomNote.size(); i++) {
    		r[ransomNote[i] - 'a'] ++;
    	}
    	for(int i = 0; i < magazine.size(); i++) {
    		m[magazine[i] - 'a'] ++;
    	}
    	for(int i = 0 ; i < 26; i++) {
    		if(m[i] < r[i]) {
    			return false;
    		}
    	}
    	return true;
    }
};
int main() {
	Solution s;
	cout<<s.canConstruct("aab", "accabaabccd");
	cout<<s.canConstruct("aaba", "accabaabccd");
	cout<<s.canConstruct("fffbfg", "effjfggbffjdgbjjhhdegh");
	cout<<s.canConstruct("bjaajgea", "affhiiicabhbdchbidghccijjbfjfhjeddgggbajhidhjchiedhdibgeaecffbbbefiabjdhggihccec");
	cout<<s.canConstruct("", "");
}
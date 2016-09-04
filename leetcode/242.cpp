#include <iostream>
using namespace std;
class Solution {
public:
	int ss[26], tt[26];
    bool isAnagram(string s, string t) {
  		if(s.size() != t.size()) {
  			return false;
  		}     
  		for(int i = 0; i < s.size(); i++) {
  			ss[s[i] - 'a'] ++;
  		}
  		for(int i = 0; i < t.size(); i++) {
  			tt[t[i] - 'a'] ++;
  		}  		
  		for(int i = 0 ; i < 26; i++) {
  			if(ss[i] != tt[i])
  				return false;
  		}
  		return true;
    }
};
int main() {
	Solution s;
	cout<<s.isAnagram("anagram", "nagaram")<<endl;
	cout<<s.isAnagram("rat", "car")<<endl;
}
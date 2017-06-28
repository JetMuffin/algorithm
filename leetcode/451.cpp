#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;
typedef pair<char, int> PII;
struct cmpByValue {
	bool operator() (const PII& a, const PII& b) {
		return a.second > b.second;
	}
};
class Solution {
public:
    string frequencySort(string s) {
  		map<char, int> m;
  		for(int i = 0 ; i < s.length(); i++) {
  			m[s[i]]++;
  		}
  		vector<PII> chars(m.begin(), m.end());
  		sort(chars.begin(), chars.end(), cmpByValue());
  		string ret;
  		for(int i = 0; i < chars.size(); i++) {
  			for(int j = 0; j < chars[i].second; j++)
  				ret += chars[i].first;
  		}
  		return ret;
    }
};
int main() {
	string str;
	Solution s;
	while(cin>>str) {
		cout<<s.frequencySort(str)<<endl;
	}
}
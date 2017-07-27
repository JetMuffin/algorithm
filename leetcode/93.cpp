#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
	vector<string> ans;
	string node[4];
	int s2i(string s) {
		int b = 1, ret = 0;
		for(int i = s.length() - 1; i >= 0; i--) {
			ret += (s[i] - '0') * b;
			b *= 10;
		}
		return ret;
	}
	void dfs(string s, int n, int st, int len) {
		if(n == 4) {
			if(s.length() == st + len) {
				node[n-1] = s.substr(st, len);
				if(s2i(node[n-1]) > 255 || (node[n-1][0] == '0' && node[n-1].length() > 1)) return;
				string ip;
				for(int i = 0; i < 4; i++) {
					ip += node[i];
					if(i != 3) {
						ip += ".";
					}
				}
				ans.push_back(ip);
			}
			return;
		}

		if(s.length() < st + len + 4 - n) return;
		node[n-1] = s.substr(st, len);
		if(s2i(node[n-1]) > 255 || (node[n-1][0] == '0' && node[n-1].length() > 1)) return;
		// printf("%d %d %d %d\n", n, st, len, s2i(node[n-1]));

		for(int i = 1; i <= 3; i++) {
			dfs(s, n+1, st + len, i);
		}
	}
	vector<string> restoreIpAddresses(string s) {
		for(int i = 1; i <= 3; i++) {
			dfs(s, 1, 0, i);
		}
		return ans;
    }
};
int main() {
	string str;
	Solution s;
	while(cin>>str) {
		vector<string> ans = s.restoreIpAddresses(str);
		for(int i = 0 ; i < ans.size(); i++) {
			cout<<ans[i]<<endl;
		}
	}
}
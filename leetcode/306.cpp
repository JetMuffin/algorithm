#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
	vector<long long> nums;
	string s;
	long long sub(int start, int end) {
		if(nums[start] == 0 && end != start) return -1;
		long long b = 1;
		long long ret = 0;
		for(int i = end; i >= start; i--) {
			ret += nums[i] * b;
			b *= 10;
		}
		return ret;
	}
	int sz(int val) {
		int len = 0, p = val;
		if(p == 0) {
			len = 1;
		} else {
			while(p) {
				len++;
				p /= 10;
			}
		}
		return len;
	}
	bool dfs(int start, long long pre, long long val) {
		cout<<start<<" "<<pre<<" "<<val<<endl;
		if(pre == -1) return false;
		
		long long p = val, len = sz(val);
		if(start+len > s.length()) return false;

		for(int i = start + len - 1; i >= start; i--) {
			cout<<(p%10) <<" "<< (s[i]-'0')<<endl;
			if((p%10) != (s[i]-'0')) return false;
			p/=10;
		}
		if(start+len == s.length()) {
			return true;
		}

		if(start+len+sz(val+pre) <= s.length() && dfs(start+len, val, val+pre)) return true;
		return false;
	}
    bool isAdditiveNumber(string num) {
    	int len = num.length();
    	nums.clear();
    	s = num;
        for(int i = 0; i < len; i++) {
        	nums.push_back(num[i] - '0');
        }
        for(int i = 0; i < len - 2; i++) {
        	for(int j = i+1; j < len - i - 1; j++) {
        		long long x = sub(0, i);
        		long long y = sub(i+1, j);
        		cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
        		if(dfs(j+1, y, x+y)) 
        			return true;
        	}
        }
        return false;
    }
};

int main() {
	string n;
	Solution s;
	while(cin>>n) {
		cout<<s.isAdditiveNumber(n)<<endl;
	}
}
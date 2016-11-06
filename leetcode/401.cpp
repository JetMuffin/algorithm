#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
    	vector<string> res;
    	for(int i = 0; i <= 1024; i++) {
    		int h = i >> 6;
    		int m = i & (0x03F);
    		if(h < 12 && m < 60) {
	    		int c = 0;
	    		int j = i;
	    		for(c = 0; j; ++c) {
	    			j &= (j-1);
	    		}		
	    		if(c == num) {
	    			string s;
		    		if(h >= 10) {
		    			s += '0' + h/10;
		    			s += '0' + h%10;
		    		} else {
		    			s += '0' + h;
		    		}
		    		s += ":";
		    		s += '0' + m/10;
		    		s += '0' + m%10;
	    			res.push_back(s);
	    		}		
    		}
    	}
    	return res;
    }
};
int main() {
	Solution s;
	int n ;
	while(cin>>n) {
		vector<string> ans = s.readBinaryWatch(n);
		for(int i = 0 ; i < ans.size(); i++) {
			cout<<ans[i]<<endl;
		}
	}
}
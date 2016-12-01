#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
    	if(x < 0) return false;
    	long b = 1;
    	int k = 10, t;
    	while(b <= x) {
    		b *= 10;
    	}
    	b /= 10;
    	t = x;
    	while(x) {
    		if((x/b) != (t%k)) {
    			return false;
    		}
    		x = x%b;
    		b /= 10;
    		t /= 10;
    	}
    	return true;
    }
};
int main() {
	Solution s;
	int n;
	while(~scanf("%d", &n)) {
		cout<<s.isPalindrome(n)<<endl;
	}
}
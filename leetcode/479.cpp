#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int largestPalindrome(int n) {
    	if(n == 1) return 9;
        int h = pow(10, n) - 1;
        int l = pow(10, n - 1);
        for(int i = h; i >= l ; i--) {
        	long long p = palindrome(i, l);
        	for(int j = h; j >= l; j--) {
        		if(p / j > h) break;
        		if(p % j == 0) {
        			cout<<p<<" "<<j<<" "<<p/j<<endl;
        			return p % 1337LL;
        		}
        	}
        }
    }
    long long palindrome(long long x, long long n) {
    	long long ret = x * n * 10LL;
    	while(x) {
    		ret += n * (x % 10);
    		x /= 10;
    		n /= 10;
    	}
    	return ret;
    }
};

int main() {
	Solution s;
	cout<<s.largestPalindrome(5)<<endl;
}
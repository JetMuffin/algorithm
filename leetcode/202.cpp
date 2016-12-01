#include <iostream>
using namespace std;
class Solution {
public:
	int digitsum(int n) {
		int sum = 0, dig;
		while(n) {
			dig = n % 10;
			sum += dig * dig;
			n /= 10;
		}
		return sum;
	}
    bool isHappy(int n) {
    	while(true) {
    		n = digitsum(n);
    		if(n == 1) {
    			return true;
    		} 
    		if(n == 4) {
    			return false;
    		}
    	}
    }
};
int main() {
	Solution s;
	int n;
	while(~scanf("%d", &n)) {
		cout<<s.isHappy(n)<<endl;
	}
}
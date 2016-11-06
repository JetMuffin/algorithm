#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
		return !(n & (n-1));
    }
};
int main() {
	Solution s;
	for(int i = 1 ; i <= 40; i++) {
		cout<<s.isPowerOfTwo(i)<<endl;
	}
}
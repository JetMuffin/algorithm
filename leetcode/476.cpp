#include <iostream>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        int res = 0, base = 1;
        while(num) {
        	int bit = (num % 2) == 0 ? 1 : 0;
        	res += bit * base;
        	num >>= 1;
        	base <<= 1;
        }
        return res;
    }
};
int main() {
	Solution s;
	int n;
	while(cin>>n) {
		cout<<s.findComplement(n)<<endl;
	}
}
#include <iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
  		int res = 0;
  		for(res = 0; n; res++) {
  			n &= (n-1);
  		}      
  		return res;
    }
};
int main() {
	Solution s;
	int n;
	while(cin>>n) {
		cout<<s.hammingWeight(n)<<endl;
	}
}
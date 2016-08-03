#include <iostream>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
  		if(b == 0) {
  			return a;
  		}  
  		int c = a ^ b;
  		int d = (a & b) << 1;
  		return getSum(c, d);
    }
};
int main() {
	Solution s;
	cout<<s.getSum(2, 3)<<endl;
}
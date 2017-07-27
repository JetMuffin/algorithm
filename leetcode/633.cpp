#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
  		int r = sqrt(c);
  		for(int i = r; i >= 1; i--) {
  			int l = sqrt(c - i * i);
  			if(l * l + i * i == c && l >= 0) {
  				return true;
  			}
  		}      
  		return false;
    }
};
int main() {
	int n;
	Solution s;
	while(cin>>n) {
		cout<<s.judgeSquareSum(n)<<endl;
	}
}
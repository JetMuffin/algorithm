#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 2147483647) return 46340;
        int t = x;
        while((t - x / t) > 0)
        	t = (x / t + t) / 2;
        return t;
    }
};

int main() {
	Solution s;
	int n;
	while(cin>>n) {
		cout<<s.mySqrt(n)<<endl;
	}
}
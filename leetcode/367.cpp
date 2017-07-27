#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i = 1; i <= 46340; i++) {
            if(i * i == num) return true;
        }
        return false;
    }
};
int main() {
	int n;
	Solution s;
	while(cin >> n) {
		cout<<s.isPerfectSquare(n)<<endl;
	}
}
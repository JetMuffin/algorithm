#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num) {
        	sum += num%10;
        	num /= 10;
        }
        if(sum >= 10) {
        	return addDigits(sum);
        }else {
        	return sum;
        }
    }
};

int main() {
	Solution t;
	int n;
	while(cin>>n) {
		cout<<t.addDigits(n)<<endl;
	}
}
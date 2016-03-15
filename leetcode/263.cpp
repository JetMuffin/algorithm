#include <iostream>
using namespace std;
class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) {
        	return false;
        } else {
        	while(num > 1) {
        		if(num % 2 == 0) {
        			num /= 2;
        		} else if(num % 3 == 0) {
        			num /= 3;
        		} else if(num % 5 == 0) {
        			num /= 5;
        		} else {
        			return false;
        		}
        	}
        	return true;
        }
    }
};

int main() {
	int n;
	while(cin>>n) {
		Solution test;
		if(test.isUgly(n)) {
			cout<<"Yes"<<endl;
		}else {
			cout<<"No"<<endl;
		}
	}
}
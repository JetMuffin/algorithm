#include <iostream>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string res = "";
        for(int i = s.length()-1; i >= 0; i--) {
        	res += s[i];
        }
        return res;
    }
};

int main() {
	Solution s;
	cout<<s.reverseString("hello")<<endl;
}
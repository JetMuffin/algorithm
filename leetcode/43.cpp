#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
	const int max_len = 500;
    string multiply(string num1, string num2) {
  		int mul[max_len];
  		memset(mul, 0, sizeof(mul));

  		for(int i = 0; i < num1.length(); i++) {
  			for(int j = 0; j < num2.length(); j++) {
  				if(mul[i + j] == -1) mul[i + j] = 0;
  				mul[i + j] += (num1[i] - '0') * (num2[j] - '0');
  				if(mul[i + j] > 9 &&  (i + j) > 0) {
  					mul[i + j - 1] += mul[i + j] / 10;
  					mul[i + j] %= 10;
  				}
  			}
  		}

  		for(int i = num1.length() + num2.length() - 1; i > 0; i--) {
  			if(mul[i] > 9) {
  				mul[i - 1] += mul[i] / 10;
  				mul[i] %= 10;
  			}
  		}

  		string ret = "";
  		if(mul[0] > 9) {
  			ret += (mul[0] / 10 + '0');
  			mul[0] %= 10;
  		}

  		bool nonzero = false;
  		for(int i = 0; i < num1.length() + num2.length() - 1; i++) {
  			if(mul[i] != 0) nonzero = true;
  			ret += (mul[i] + '0');
  		}

  		if(!nonzero) return "0";

  		return ret;
    }
};

int main() {
	Solution s;
	string a, b;
	while(cin>>a>>b) {
		cout<<s.multiply(a, b)<<endl;
	}
}
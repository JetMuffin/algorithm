#include <iostream>
#include <cmath>
using namespace std;

class Solution {
  public:
	bool isPowerOfThree(int n) {
	  if(n <= 0) return false;
	  double logn = log10(n)/log10(3);
	  if(logn - int(logn) == 0) {
		return true;
	  } else {
		return false;
	  }
	}
};

int main(){
  Solution test;
  int n;
  while(cin>>n){
	if(test.isPowerOfThree(n)) {
	  cout<<"yes"<<endl;
	} else {
	  cout<< "no"<<endl;
	}
  }
}

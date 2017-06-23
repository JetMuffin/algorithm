#include <cstring>
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int findLUSlength(string a, string b) {
  		int lena = a.length();
  		int lenb = b.length();
  		if(lena != lenb) {
  			return max(lena, lenb);
  		} 
  		if(a == b) {
  			return -1;
  		} else {
  			return lena;
  		}
    }
};
int main() {
	string a, b;
	Solution s;
	while(cin>>a>>b) {
		cout<<s.findLUSlength(a, b)<<endl;
	}
}
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> res;
            for(int i = 1; i <= n; i++) {
                if(i % 5 == 0 && i % 3 == 0) {
                    res.push_back("FizzBuzz");
                } else if(i % 5 == 0) {
                    res.push_back("Buzz");
                } else if(i % 3 == 0) {
                    res.push_back("Fizz");
                } else {
                    stringstream ss;
                    string s;
                    ss<<i;
                    ss>>s;
                    res.push_back(s);
                }
            }
            return res;
        }
};
int main() {
    Solution s;
    vector<string> v = s.fizzBuzz(25);
    for(vector<string>::iterator it=v.begin(); it!= v.end(); it++) {
        cout<<*it<<endl;
    }
}

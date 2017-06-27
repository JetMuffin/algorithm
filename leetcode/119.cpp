#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
class Solution {
    public:
    vector<int> getRow(int rowIndex) {
            long long a = 1;
            vector<int> res;
            res.push_back(a);
            for(int i = rowIndex; i >= 1; i--) {
                        a = (long long) (a * i) / (long long) (rowIndex + 1 - i);
                        res.push_back((int)a);
                    }
            return res;
        }
};
int main() {
    Solution s;
    int n;
    while(~scanf("%d", &n)) {
        vector<int> ans = s.getRow(n);
        for(int i = 0; i < ans.size(); i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
}

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
bool judge(int x) {
    vector<int> p;
    while(x) {
        p.push_back(x % 10);
        x /= 10;
    }
    for(int i = 0, j = p.size() - 1; i <= j; i++, j--) {
        if(p[i] != p[j]) return false;
    }
    return true;
}
int main() {
    int ans = 0;
    for(int i = 100; i <= 999; i++) {
        for(int j = i; j <= 999; j++) {
            int t  = i * j;
            if (judge(t)) {
                ans = max(ans, t);
                cout << ans << endl;
            }
        }
    }
}

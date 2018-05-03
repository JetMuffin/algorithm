#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
bool check(int x) {
    int sum = 0;
    int t;
    bool flag = false;
    while(x) {
        t = x % 10;
        sum += t;
        if (t == 9) flag = true;
        x /= 10;
    }
    if (sum % 9 == 0) return false;
    return flag;
}
int main() {
    int t,cas=0,f,l;
    scanf("%d", &t);
    while(t--) {
        cas++;
        scanf("%d%d", &f, &l);
        int ans = 0;
        map<int, int> m;
        ans = (l - f) / 9 + (f%9 + (l-f)%9)/9;
        for(int i = f; i <= l; i++) {
            if (check(i)) {
                ans++;
            } else {
                if(i%9!=0) {
                    m[i%9]++;
                }
            }
        }
        printf("Case #%d: %d\n", cas, l - f + 1 - ans);
    }
}

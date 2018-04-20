#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
int main() {
    int ans = 1, t;
    for(int i = 1; i <= 20; i++) {
        t = gcd(ans, i);
        ans = ans / t * i;
    }
    cout << ans << endl;
}

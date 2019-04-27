#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn = 1000010;
int find(ll x) {
    int n = 0;
    while(x != 1) {
        if (x % 2 == 0) {
            x /= 2;
        } else {
            x = x * 3 + 1;
        }
        n++;
    }
    n++;
    return n;
}

int main() {
    int maxx = 0, maxt = -1, t;
    for(int i = 2; i < 1000000; i++) {
        t = find(i);
        if (t > maxx) {
            maxx = t;
            maxt = i;
        }
        printf("%d %d %d %d\n", i, t, maxx, maxt);
    }
}

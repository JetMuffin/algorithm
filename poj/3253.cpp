#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
int a[20005];
struct cmp {
    bool operator() (ll &a, ll &b) const {
        return a > b;
    }
};
int main() {
    int n;
    while(~scanf("%d", &n)) {
        priority_queue<ll, std::vector<ll>, cmp> q;
        ll t;
        for(int i = 0; i < n ; i++) {
            scanf("%lld", &t);
            q.push(t);
        }
        ll a, b;
        ll ans = 0;
        while(q.size() > 1) {
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            ans += (a + b);
            q.push(a+b);
        }
        printf("%lld\n", ans);
    }
}

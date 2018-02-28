#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
class Solution {
    public:
        long long mod = 1e9+7;
        long long fac[100010];
        long long inv[100010];
        void init() {
            fac[0] = 1;
            inv[0] = 1;
            for(int i = 1; i <= 100000; i++) {
                fac[i] = fac[i - 1] * i % mod;
            }
            inv[1] = 1;
            for(int i = 2; i <= 100000; i++) {
                inv[i] = inv[mod % i] * (mod - mod / i) % mod;
            }
            for(int i = 2; i < 100000; i++) {
                inv[i] = inv[i] * inv[i-1] % mod;
            }
        }

        int checkRecord(int n) {
            long long ans = 0;
            init();
            for(int a = 0; a <= min(1, n); a++) {
                for(int l = 0; l <= min(2, n-a); l++) {
                    long long t = fac[n] * inv[a] % mod * inv[l] % mod * inv[n-a-l] % mod;
                    cout<<a<<" "<<l<<" "<<n-a-l<<" "<<t<<endl;
                    ans = (ans + t) % mod;
                }
            }
            return ans;
        }
};
int main() {
    int n;
    Solution s;
    while(cin>>n) {
        cout<<s.checkRecord(n)<<endl;
    }
}


#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000000;
bool isPrime[maxn];
vector<int> prime;
int main() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < maxn; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
        for(int j = 0; j < prime.size() && prime[j] * i < maxn; j++) {
            isPrime[prime[j] * i] = false;
        }
    }
    printf("%d\n", prime.size());
    printf("%d\n", prime[10000]);
    for(int i = 0; i < 10; i++) {
        cout << prime[i] << endl;
    }
}

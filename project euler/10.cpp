#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2000000;
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
    long long sum = 0;
    for(int i = 0; i < prime.size(); i++) {
        if(prime[i]>2000000) break;
        sum += prime[i];
    }
    cout << sum << endl;
}

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    long long x = 600851475143;
    long long i = 2;
    vector<long long> p;
    do {
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            p.push_back(i);
        } else
        i++;
    } while (x != 1);
    printf("%lld\n", p[p.size() - 1]);
}

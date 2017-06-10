#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000010;
int prime[maxn], primes[maxn];
int cnt = 0;
void Prime() {
	for(int i = 0; i < maxn; i++) prime[i] = 1;
	prime[0] = prime[1] = 0;
	for(int i = 2; i < maxn; i++) {
		if(!prime[i]) continue;
		primes[cnt++] = i;
		for(int j = i + i; j < maxn; j += i) prime[j] = 0;
	}
}

int main() {
	Prime();
	int n;
	while(~scanf("%d", &n)) {
		for(int i = 0; primes[i] < n; i++) cnt = i;
		for(int i = 0; i < cnt; i++) {
			if(prime[n - primes[i]]) {
				printf("%d %d\n", primes[i], n - primes[i]);
				break;
			}
		}
	}
}
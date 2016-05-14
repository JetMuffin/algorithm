#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define maxn 1000010
long long f[maxn];
void init() {
	f[1] = 1;
	f[2] = 2;
	for(long long i = 3; i <= maxn; i++) {
		f[i] = (f[i-1]+(i-1)*f[i-2])%mod;
	}
}

int main() {
	int t ,cas=0;
	init();
	scanf("%d", &t);
	while(t--) {
		cas++;
		printf("Case #%d:\n", cas);
		int n; 
		scanf("%d", &n);
		printf("%lld\n", f[n]);
	}
}
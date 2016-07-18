#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 3000010

int phi[maxn];
int prime[maxn];
bool vis[maxn];

void init() {
  int tot = 0;
  for(int i = 2; i < maxn; i++) {
	if(!vis[i]) {
	  prime[tot++] = i;
	  phi[i] = i - 1;
	}
	for(int j = 0 ; j < tot && i * prime[j] < maxn; j++) {
	  vis[i * prime[j]] = 1;
	  phi[i * prime[j]] = i % prime[j] == 0 ? prime[j]*phi[i] : phi[i]*(prime[j] - 1);
	}
  }
}

int main() {
  int a, b;
  init();
  while(~scanf("%d%d", &a, &b)) {
  	long long ans = 0;
  	for(int i = a ; i <= b; i++) {
  		ans += phi[i];
  	}
  	printf("%lld\n", ans);
  }
}



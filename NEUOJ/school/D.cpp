#include <iostream>
#include <cstdio>
using namespace std;
// const int maxn = 20;
const int maxn = 1000010;
long long f[maxn];
bool vis[maxn];
void init() {
	memset(vis,0,sizeof(vis));
	for(int i = 0; i <= maxn; i++) f[i] = i;
	for(int i = 2; i <= maxn; i++) {
		if(!vis[i]) {
			f[i] = i;
			for(int j = 2*i; j <= maxn; j+=i) {
				vis[j] = true;
				f[j] = f[j] + f[j-i];
			}
		}
	}
}
int main() {
	init();
	int t, cas = 0;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		cas ++;
		printf("Case #%d: %lld\n",cas, f[n]);
	}
}
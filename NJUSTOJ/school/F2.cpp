#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 10010;
struct node {
	int v, i;
}a[maxn];
int cmp(node a, node b) {
	return a.v < b.v;
}
bool vis[maxn];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		memset(vis, 0 , sizeof(vis));
		scanf("%d", &n);

		for(int i = 0 ; i < n; i++) {
			scanf("%d", &a[i].v);
			a[i].i = i;
		}
		sort(a, a+n, cmp);
		for(int i = 0 ; i < n ; i++) {
			// cout<<a[i].v<<" "<<a[i].i<<endl;
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			cout<<a[i].v<<" "<<a[i].i<<" "<<i<<"#"<<endl;
			if(!vis[a[i].i]) {
				ans ++;
				vis[a[i].i] = true;
				for(int j = i + 1, k = a[i+1].i; j < n, k<n; j++) {
					if(!vis[k]) {
						cout<<a[j].v<<" "<<a[j].i<<" "<<j<<"@"<<endl;
						vis[j] = true;
						j = m[a[k+1].i];
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}
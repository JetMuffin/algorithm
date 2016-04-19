#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define LL long long
using namespace std;

const int maxn = 20010;
struct node {
	int v, i;
}a[maxn];
int cmp(node a, node b) {
	return a.v < b.v;
}
bool vis[maxn];
map<int,int>m;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		memset(vis, 0 , sizeof(vis));
		memset(a, 0, sizeof(a));
		m.clear();
		scanf("%d", &n);
		// cout<<"n:"<<n<<endl;
		for(int i = 0 ; i < n; i++) {
			scanf("%d", &a[i].v);
			a[i].i = i;
		}
		sort(a, a+n, cmp);
		for(int i = 0; i < n; i++) {
			m[a[i].i] = i; 
		}
		// for(int i = 0 ; i < n ; i++) {
		// 	cout<<a[i].v<<" "<<a[i].i<<endl;
		// }
		// cout<<"--"<<endl;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			// cout<<i<<" "<<a[i].i<<" "<<a[i].v<<" "<<vis[i]<<endl;
			if(!vis[a[i].i]) {
				// cout<<i<<" "<<a[i].i<<" "<<a[i].v<<endl;
				ans ++;
				vis[a[i].i] = true;
				for(int j = a[i].i + 1; j < n; j++) {
					if(!vis[j]) {
						vis[j] = true;
						j = m[j];
						// cout<<"!"<<j<<endl;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}

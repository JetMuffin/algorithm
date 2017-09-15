#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 100010;
int fa[maxn];
int tot = 0;
map<string, int> m;
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void init() {
	for(int i = 0; i < maxn; i++) {
		fa[i] = i;
	}
}
int merge(int x, int y) {
	fa[find(x)] = find(y);
}
int id(string x) {
	if(m[x] == 0) {
		m[x] = ++tot;		
		return tot;
	} else {
		return m[x];
	}
}
int main() {
	int n;
	string op, a, b;
	init();
	scanf("%d", &n);
	while(n--) {
		cin>>op>>a>>b;
		if(op[0] == '0') {
			merge(id(a), id(b));
		} else if(op[0] == '1') {
			int x = find(id(a));
			int y = find(id(b));
			if(x == y) {
				puts("yes");
			} else {
				puts("no");
			}
		}
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int maxn = 2000;
int pre[maxn];
int tag[maxn];
int tot = 0;
map<string, int> names;
map<int, string> ids;
int hashx(string name) {
	if(!names.count(name)) {
		tot++;
		names[name] = tot;
		ids[tot] = name;
		return tot;
	} else {
		return names[name];	
	}
}
void dfs(int x) {
	tag[x] = 1;
	if(pre[x] == 0) return;
	dfs(pre[x]);
}
int dfs2(int x) {
	if(tag[x] == 1) return x;
	if(pre[x] == 0) return -1;
	if(tag[pre[x]] == 1) return pre[x];
	dfs2(pre[x]);
}
int main() {
	int n, q;
	string a, b;
	scanf("%d", &n);
	memset(pre, 0, sizeof(pre));

	for(int i = 0; i < n; i++) {
		cin>>a>>b;
		pre[hashx(b)] = hashx(a);
	}

	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		memset(tag, 0, sizeof(tag));
		cin>>a>>b;

		int c = hashx(a);
		int d = hashx(b);

		dfs(c);	

		int ans = dfs2(d);
		if(ans != -1) {
			cout<<ids[ans]<<endl;
		} else {
			cout<<-1<<endl;
		}
	}
}
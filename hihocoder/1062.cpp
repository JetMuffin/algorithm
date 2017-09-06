#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
const int maxn = 2000;
int pre[maxn];
bool tag[maxn];
int main() {
	int n, q;
	string a, b;
	scanf("%d", &n);
	int cnt = 1;
	map<string, int> names;
	map<int, string> ids;
	for(int i = 0; i < n; i++) pre[i] = -1;		
	for(int i = 0; i < n; i++) {
		cin>>a>>b;
		if(names[a] == 0) {
			names[a] = cnt;
			ids[cnt] = a;
			cnt++;
		}
		if(names[b] == 0) {
			names[b] = cnt;
			ids[cnt] = b;
			cnt++;
		}

		pre[names[b]] = names[a];
	}

	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		memset(tag, 0, sizeof(tag));
		cin>>a>>b;

		int c = names[a];
		int d = names[b];

		while(c != -1) {
			tag[c] = true;
			c = pre[c];
		}

		while(d != -1 && !tag[d]) d = pre[d];

		if(d != -1) {
			cout<<ids[d]<<endl;
		} else {
			cout<<-1<<endl;
		}
	}
}
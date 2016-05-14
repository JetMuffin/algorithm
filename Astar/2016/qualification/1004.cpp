#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
char s[50];
map<string, int> m;
int cmp(char a, char b) {
	return a < b;
}
int main() {
	int n;
	while(~scanf("%d", &n)) {
		m.clear();
		for(int i = 0 ; i < n; i++) {
			scanf("%s", s);
			int len = strlen(s);
			sort(s, s+len, cmp);
			printf("%d\n", m[s]);
			m[s]++;
		}

	}
}
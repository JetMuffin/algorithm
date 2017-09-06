#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 3000010;
char s[maxn];
char str[maxn];
int p[maxn];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", str);
		s[0] = '*';
		s[1] = '#';
		int len = strlen(str);
		for(int i = 0 ; i < len; i++) {
			s[2*i+3] = '#';
			s[2*i+2] = str[i];
		}
		s[2*len+2] = '\0';
		int id = 0, maxr = 0, ans = 1;
		len = 2*len+2;
		for(int i = 0; i < len; i++) {
			if(maxr > i) {
				p[i] = min(maxr - i, p[2*id-i]);
			} else {
				p[i] = 1;
			}
			while(s[i-p[i]] == s[i+p[i]]) {
				p[i]++;
			}
			if(i+p[i] > maxr) {
				maxr = i + p[i];
				id = i;
			}
			if(p[i] > ans) {
				ans = p[i];
			}
		}

		printf("%d\n", ans-1);
	}
}
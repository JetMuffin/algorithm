#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char s[2000];
int a[26];
int main() {
	int t;
	scanf("%d", &t);
	getchar();
	while(t--) {
		gets(s);
		memset(a,0,sizeof(a));
		int len = strlen(s);
		for(int i = 0 ; i < len; i++) {
			if(s[i]>='a' && s[i]<='z') {
				a[s[i]- 'a'] ++;
			}
		}
		int ans = 0;
		for(int i = 0; i < 26; i++) {
			if(a[i] > 0) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100010];
int main() {
	int t, cas = 0;
	scanf("%d", &t);
	while(t--) {
		cas++;
		printf("Case #%d:\n", cas);
		int k;

		getchar();
		gets(s);
		scanf("%d", &k);
		int len = strlen(s);
		int h = len/k;
		int step = h*k == len ? h:h+1;
		int l = len%k;
		if(l == 0) {
			for(int i = 1; i <= h; i++) {
				int last = i;
				printf("%c", s[last-1]);
				// printf("%d\n", last);
				for(int j = 2; j <= k; j++) {
					last = last + step;
					// printf("%d\n", last);
					printf("%c", s[last-1]);
				}
			}
			printf("\n");
			continue;
		}
		for(int i = 1; i <= h; i++) {
			int last = i;
			printf("%c", s[last-1]);
			// printf("%d\n", last);
			for(int j = 2; j <= k; j++) {

				if(j-1 <= l) {
					last = last + step;
				} else {
					last = last + step - 1;
				}
				// printf("%d\n", last);
				printf("%c", s[last-1]);
			}
		}
		if(h*k < len) {
			int last = h+1;
			// printf("%d\n", last);
			printf("%c", s[last-1]);
			for(int j = 2; j <= l; j++) {
				last = last + step;
				// printf("%d\n", last);
				printf("%c", s[last-1]);
			}
		}
		printf("\n");
	}
}
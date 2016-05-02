#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[2000];
int main() {
	int t, n, m;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d",&n, &m);
		scanf("%s", s);
		int len = strlen(s);
		for(int i = 0; i < len; i++) {
			printf("%c", s[i]);
			if((i+1)%m == 0) {
				printf("\n");
			}
		}
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[10000];
char rev[10000];
int main() {
	while(~scanf("%s", s)) {
		memset(rev,0,sizeof(rev));
		int len = strlen(s);
		for(int i = len-1; i>=0; i--) {
			rev[len-1-i] = s[i]; 
		}
		int ok = true;
		for(int i = 0; i < len; i++) {
			if(s[i] != rev[i]) {
				ok = false;
				break;
			}
		}
		if(ok)
			puts("Yes");
		else
			puts("No");
	}
}
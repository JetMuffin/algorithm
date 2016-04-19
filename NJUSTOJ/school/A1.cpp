#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

char s[2010];
char r[2010];
int a[1010];
int b[1010];
string c;
string d;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		c = "";
		d = "";
		scanf("%s", s);
		scanf("%s", r);
		int lens = strlen(s);
		int lenr = strlen(r);
		char last = s[0];
		c += s[0];
		for(int i = 1 ; i < lens; i++) {
			if(s[i] != last) {
				c += s[i];
				last = s[i];
			}
		}
		last = r[0];
		d+= r[0];
		for(int i = 1; i < lenr; i++) {
			if(r[i] != last) {
				d += r[i];
				last = r[i];
			}
		}
		// cout<<c<<" "<<d<<endl;
		if(c==d) {
			puts("Yes");
		}else {
			puts("No");
		}
	}
}
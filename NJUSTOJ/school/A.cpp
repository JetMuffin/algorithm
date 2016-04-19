#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

char s[1010];
char r[1010];
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
		for(int i = 0 ; i < lens; i++) {
			char kk = s[i];
			c += kk;
			while(s[i] == kk && i < lens) {
				i++;
			}
			i--;
		}
		for(int i = 0; i <lenr; i++) {
			char kk = r[i];
			d+= kk;
			while(r[i] == kk && i < lenr) {
				i++;
			}
			i--;
		}	
		cout<<c<<" "<<d<<endl;
		if(c==d) {
			puts("Yes");
		}else {
			puts("No");
		}
	}
}
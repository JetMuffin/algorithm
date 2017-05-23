#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[5050];
int main() {
	int t, cas = 0;
	scanf("%d", &t);
	while(t--) {
		cas++;
		int n, m;
		scanf("%d[%s]", &n, s);
		switch(s[0]) {
			case 'B':
				m = 0;
				break;
			case 'K':
				m = 1;
				break;
			case 'M':
				m = 2;
				break;
			case 'G':
				m = 3;
				break;
			case 'T':
				m = 4;
				break;
			case 'P':
				m = 5;
				break;
			case 'E':
				m = 6;
				break;
			case 'Z':
				m = 7;
				break;
			case 'Y':
				m = 8;
				break;
		}
		double base = (1000.0/1024.0);
		double ans = 1.0;
		for(int i = 0; i < m; i++) {
			ans *= base;
		}
		printf("Case #%d: %.2f%%\n",cas, (1-ans)*100);
	}
}
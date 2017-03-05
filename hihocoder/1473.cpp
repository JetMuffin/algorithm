#include <cstdio>
#include <iostream>
using namespace std;
int L, F, D, T;
int gcd(int a, int b) {
	return b == 0? a: gcd(b, a%b);
}
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &L, &F, &D);
		if(L == 0 || D == 0) puts("NO");
		int g = gcd(L, D);
		if(g >= F || g == 0)
			puts("YES");
		else
			puts("NO");
	} 
}
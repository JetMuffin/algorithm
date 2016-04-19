#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
int main() {
	int t;
	LL n;
	// a[0] = a[1] = b[0] = b[1] = c[0] = c[1] = 0;
	// for(int i = 2; i <= maxn; i++) {
	// 	if(i %2 == 0) {
	// 		a[i] = a[i-1] + 1;
	// 		b[i] = b[i-1] + 1; 
	// 		c[i] = c[i-1] + 1;
	// 		while(b[i] >= 2 || c[i] >= 4) {
	// 			if(b[i] >= 2) {
	// 				a[i] += b[i]/2;
	// 				c[i] += b[i]/2;
	// 				b[i] = b[i] - b[i]/2*2 + b[i]/2;
	// 			}
	// 			if(c[i] >= 4) {
	// 				a[i] += c[i]/4;
	// 				b[i] += c[i]/4;
	// 				c[i] = c[i] - c[i]/4*4 + c[i]/4;
	// 			}
	// 		}
	// 	} else {
	// 		a[i] = a[i-1];
	// 		b[i] = b[i-1];
	// 		c[i] = c[i-1];
	// 	}
	// }	
	// for(int i = 0; i < 35; i++) {
	// 	cout<<i<<" "<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
	// }
	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &n);
		if(n == 0 || n == 1) {
			puts("0");
			continue;
		} else if(n==2 || n == 3){
			puts("1");
		} else {
			printf("%lld\n", 4*(n/2)-5);
		}
	}
}
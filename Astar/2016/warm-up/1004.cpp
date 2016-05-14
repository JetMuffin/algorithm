#include <iostream>
#include <cmath>
using namespace std;
const double eps=1e-6;
const double pi=acos(-1.0);
int main() {
	int t, cas= 0;
	scanf("%d", &t);
	while(t--) {
		cas++;
		printf("Case #%d:\n", cas);
		int n;
		double a, r;
		scanf("%d%lf%lf",&n, &a, &r);
		double R = (a/2)/tan(pi/n);
		if(r<R)
			puts("Give me a kiss!");
		else 
			puts("I want to kiss you!");
	}
}
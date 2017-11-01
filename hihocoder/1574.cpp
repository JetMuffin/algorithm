#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
const int maxn = 100010;
double a[maxn], x[maxn];
int main() {
	int n;
	double t, m;
	while(~scanf("%d", &n)) {
		scanf("%lf", &m);
		for(int i = 0; i < n; i++) {
			scanf("%lf", &a[i]);
		}
		double sum;
		for(int i = 0; i < n; i++) {
			sum += a[i];
		}
		for(int i = 0; i < n; i++) {
			x[i] = m / sum * a[i];
		}
		double ans = 0;
		for(int i = 0; i < n; i++) {
			ans += a[i] * log(x[i]);
		}
		printf("%.5lf\n", ans);
		for(int i = 0; i < n; i++) {
			printf("%.5lf%c", x[i], i==(n-1)? '\n':' ');
		}
	}
}
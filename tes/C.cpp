#include <iostream>
using namespace std;
const double pi = 3.14159265358979323846;
int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		double ans = n * n * pi;
		printf("%.*lf\n", ans, m);
	}
}
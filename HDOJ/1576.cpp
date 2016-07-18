/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11123156
*/

#include <iostream>
using namespace std;
const int mod = 9973;

int extgcd(int a, int b, int &x, int &y) {
  if(b == 0) {
	x = 1;
	y = 0;
	return a;
  }
  int d = extgcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

int reverse(int a, int n) {
  int x, y;
  int d = extgcd(a, n, x, y);
  if (d == 1) return (x%n+n)%n;
  else return -1;
}

int main() {
  int t;
  int n, b;
  scanf("%d", &t);
  while(t--) {
	scanf("%d%d", &n, &b);
	int x = reverse(b, mod);
	printf("%d\n", n*x%mod);
  }
}

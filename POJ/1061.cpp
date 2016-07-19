#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
ll extgcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
	x = 1;
	y = 0;
	return a;
  }
  ll d = extgcd(b, a%b, x, y);
  ll t = x;
  x = y;
  y = t - a/b*y;
  return d;
}
int main() {
  ll x, y, m, n, l, e, f;
  while(~scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l)) {
	ll a = n - m;
	ll b = l;
	ll c = x - y;
	ll d = extgcd(a, b, e, f);
	if(c %d != 0) {
	  puts("Impossible");
	} else {
	  b /= d;
	  c /= d;
	  e *= c;
	  printf("%lld\n", (e%b+b)%b);
	}
  }
}

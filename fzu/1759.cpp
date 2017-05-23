#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1000005;
typedef long long ll;

char str[maxn];

int phi(int n){
  int res = n;
  for(int i = 2; i * i <= n; i++){
	if(n % i == 0){
	  res = res - res / i;
	  while(n % i == 0) n /= i;
	}
  }
  if(n > 1)
	res = res - res / n;
  return res;
}

ll multi(ll a, ll b, ll m){
	ll ans = 0;
	a %= m;
	while(b){
		if(b & 1){
			ans = (ans + a) % m;
			b--;
		}
		b >>= 1;
		a = (a + a) % m;
	}
	return ans;
}

ll quickmod(ll a, ll b, ll m){
	ll ans = 1;
	a %= m;
	while(b){
		if(b & 1){
			ans = multi(ans, a, m);
			b--;
		}
		b >>= 1;
		a = multi(a,a,m);
	}
	return ans;
}

int main(){
 	ll a,c;
 	while(~scanf("%lld %s %lld", &a, str, &c)){
 		ll len = strlen(str);
 		ll ans = 0;
 		ll p = phi(c);
 		if(len <= 15){
 			for(int i = 0 ; i < len; i++)
 				ans = ans * 10 + str[i] - '0';
 		}else{ // A^B%C = A^(B%phi(C)+phi(C))%C
 			for(int i = 0 ; i < len ; i++){
 				ans = ans * 10 + str[i] - '0';
 				ans %= p;
 			}
 			ans += p;
 		}
 		printf("%lld\n", quickmod(a,ans,c));
 	}
}

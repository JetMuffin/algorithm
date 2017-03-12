#include <iostream>
using namespace std;
#define ll long long
const ll mod = 1000000007;
ll n, m;
ll factor(ll n) {
	ll res = 1;
	for(int i = 2; i <= n; i++) {
		res = res * i % mod;
	}
	return res;
}

void ext_gcd( ll a ,ll b,ll &x,ll &y) {  
     if( b == 0 ) {  
         x = 1;  
         y = 0;  
     }  
     else {  
          ext_gcd( b,a%b,x,y );  
          ll t;  
          t = x;  
          x = y;  
          y = t - a/b*y;  
     }  
}  

ll getNN(ll x) {  
        ll now , t;  
        ext_gcd( x, mod,now,t );  
        return (now%mod+mod)%mod;  
}

int main() {
	while(~scanf("%lld%lld", &n, &m)) {
		ll res = factor(n * m);
		for(int i = 0; i < n; i++) {
			res = res * factor(i) % mod;
		}

		for(int i = 0; i < n; i++) {
			res = (res * getNN(factor(m+i)))% mod;
		}
		
		printf("%lld\n", res);
	}
}
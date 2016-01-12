#include <iostream>
using namespace std;
#define LL long long
LL extgcd(LL a,LL b,LL &x,LL &y){
	if(b == 0){
		x=1;
		y=0;
		return a;
	}
    LL d = extgcd(b, a%b, y, x);
    y -= x*(a/b);
    return d;
}
int main(){
//	freopen("in.txt","r",stdin);
	LL A,B,C,K;
	while(~scanf("%lld%lld%lld%lld",&A,&B,&C,&K)){
		if(A==0 && B ==0 && C ==0 & K==0)
			break;
		LL x, y;
		LL m = (1LL << K);
		LL gcd = extgcd(C, m, x, y);
		LL b = (B - A + m) % m;
		LL t = m / gcd; 
		if(b % gcd == 0){
			LL ans = (b / gcd * x) % m;	
//			ans = (m + ans) % m;
			ans = (ans % t + t) % t;
			cout<<ans<<endl;
		}else{
			cout<<"FOREVER"<<endl;
		}
	}
}
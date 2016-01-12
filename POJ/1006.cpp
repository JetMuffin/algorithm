#include <iostream>
using namespace std;
#define LL long long
int m[3] = {23, 28, 33};
int a[3];
int extgcd(int a,int b,int &x,int &y){
	if(b == 0){
		x=1;
		y=0;
		return a;
	}
    int d = extgcd(b, a%b, y, x);
    y -= x*(a/b);
    return d;
}
int crt(int n){
	int M = 1;
	for(int i = 0; i < n; ++i)
		M *= m[i];
	int ret = 0;
	for(int i = 0; i < n; ++i){
		int x, y;
		int t = M/m[i];
		extgcd(t, m[i], x, y);
		ret = (ret + t *x * a[i]) % M;
	}
	return ret;
}
int main(){
//	freopen("in.txt","r",stdin);
	int p, e, i, d;
	int x,y;
	int cnt = 0;
	while(~scanf("%d%d%d%d",&p,&e,&i,&d)){
		cnt++;
		if(p==-1 && e ==-1 && i ==-1 & d==-1)
			break;
		a[0] = p;
		a[1] = e;
		a[2] = i;
		int ans = crt(3);
		ans = (ans - d) % 21252;
		if(ans <= 0)
			ans += 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",cnt,ans);
	}
}
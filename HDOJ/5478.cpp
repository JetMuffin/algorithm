#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
const int maxn =200010;
LL a[maxn];
LL b[maxn];
LL t[maxn];
LL pow_mod(LL a,LL b,LL mod)  
{  
    LL res=a,ans = 1 ;  
    while(b)  
    {  
        if(b&1) ans = (ans*res)%mod ;  
        b>>=1 ;  
        res= (res*res)%mod ;  
    }  
    return ans%mod;  
}  
int main(){
    int c,k1,b1,k2;
    int cnt = 0;
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d%d",&c,&k1,&b1,&k2)){
        cnt++;
        printf("Case #%d:\n", cnt);
        // for(int i = 1 ; i < maxn; i++){
        //     a[i] = pow_mod(i, k1, c);
        //     b[i] = pow_mod(i, k2, c);
        // }
        int flag = 1;
        for(int i = 1; i < c; i++){
            int t = pow_mod(i, b1+k1, c);
            int bb = c-t;
            if(bb <= 0) continue;
            LL x1 = pow_mod(i, k1, c);
            LL x2 = pow_mod(bb, k2, c);
//            cout<<i<<" "<<bb<<" "<<x1<<" "<<x2<<endl;
            if(x1 == x2){
                flag = 0;
                printf("%d %d\n", i,bb);
            }
        }
        if(flag){
            puts("-1");
        }
    }
}
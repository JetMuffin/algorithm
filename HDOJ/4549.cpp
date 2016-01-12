/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=12886918
*/

#include <iostream>
#include <cstring>
using namespace std;
#define LL long long
const int N = 2;
const long long MOD = 1000000007;
struct Mat{
    LL m[N][N];
};
Mat operator * (Mat a,Mat b){
    Mat c;
    memset(c.m,0,sizeof(c.m));
    for(int i = 0 ; i < N; i++)
        for(int j = 0 ; j < N; j++)
            for(int k = 0 ; k < N; k++)
            {
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % (MOD-1);
            }
    return c;
}
Mat operator ^ (Mat a,LL k){
    Mat c;
    memset(c.m,0,sizeof(c.m));
    for(int i = 0; i < N; i++)
            c.m[i][i] = 1;
    while(k){
        if(k&1)
            c = c * a;
        a = a * a;
        k >>= 1;
    }
    return c;
}
LL quick_pow(LL a,LL n){
    LL tmp = 1;
    while(n){
        if(n&1)
            tmp = tmp * a % MOD;
        n >>= 1;
        a = a * a % MOD;
    }
    return tmp;
}
int main()
{
    //freopen("in.txt","r",stdin);
    LL a,b,n;
    while(~scanf("%I64d%I64d%I64d",&a,&b,&n))
    {
        if(n==0) printf("%I64d\n",a);
        else if(n==1)printf("%I64d\n",b);
        else{
            Mat base = {1,1,1,0};
            base = base ^ (n-1);
            LL c = base.m[0][0];
            LL d = base.m[0][1];
            LL ans = (quick_pow(a,d) * quick_pow(b,c))%MOD;
    //        cout<<c<<" "<<d<<endl;
        printf("%I64d\n",ans);                
        }

    }
} 
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=12911920
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
const int N = 2;
const long long MOD = 10000007;
LL a[100005];
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
                c.m[i][j] = (c.m[i][j]%MOD + (a.m[i][k]%MOD) * (b.m[k][j]% MOD) % MOD) % MOD;
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
    LL n,k;
    while(~scanf("%I64d%I64d",&n,&k))
    {
        LL mx = 0;
        LL mxx = 0;
        LL sum = 0;
        for(int i = 0 ; i <n;i++)
        {
            scanf("%I64d",&a[i]);
            sum = (sum + a[i])%MOD;
            if(a[i]>mx)
            {
                mxx = mx;
                mx = a[i];
            }
            else if(a[i]>mxx)
                mxx = a[i];
        }
        sort(a,a+n);
        mx = a[n-1]% MOD;
        mxx = a[n-2]% MOD;
        //cout<<mx<<" "<<mxx<<endl;
        //cout<<sum<<endl;
        Mat base = {1,1,1,0};
        Mat mm = base ^ (k+2);
        LL c = mm.m[0][1]-1 % MOD;
        LL d = mm.m[0][0]-2 % MOD;
        LL ans = (mx * d% MOD + mxx*c% MOD + sum% MOD)%MOD;
        //cout<<c<<" "<<d<<endl;
        cout<<ans<<endl;
    }
}
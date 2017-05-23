/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11441714
*/

//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
#define usint unsigned int
#define mz(array) memset(array, 0, sizeof(array))
#define minf(array) memset(array, 0x3f, sizeof(array))
#define REP(i,n) for(i=0;i<(n);i++)
#define FOR(i,x,n) for(i=(x);i<=(n);i++)
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define WN(x) printf("%d\n",x);
#define RE  freopen("D.in","r",stdin)
#define WE  freopen("1biao.out","w",stdout)

ll farm(ll x,ll k) {
    ll i,now,mo;
    ll pre,cnt,maxc=100;
    pre=-1;
    cnt=1;
    now=x;
    for(i=1; i<=k; i++) {
        mo=now%i;
        if(mo!=0) {
            now+=i-mo;
        }
        if(cnt>=maxc) {
            now+=pre*(k-i);
            break;
        }
        if(i-mo==pre)cnt++;
        else cnt=1;
        pre=i-mo;
//        cout<<i<<endl;
    }
    return now;
}

int main() {
    int cas=1, ans;
    ll x,k,now,i,mo,pre,ppre,flag;
    while(scanf("%I64d%I64d",&x,&k)!=EOF) {
        if(x==0 && k==0)break;
        printf("Case #%d: %I64d\n",cas++,farm(x,k));
    }
    return 0;
}
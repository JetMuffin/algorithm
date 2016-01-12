/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13342153
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<time.h>
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned int UI;
typedef int Int;
using namespace std;
const int N=0,M=0,L=0,Z=1e9+7,t30=1<<30,maxint=2147483647,ms31=522133279,ms63=1061109567,ms127=2139062143;
const double eps=1e-8,PI=acos(-1.0);//.0
struct A{};
map<int,int>mop;
int casenum,casei,inf;
int n,m,i,x;
template <class T>
inline void scan_d(T &ret) 
{
    char c; ret=0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        mop.clear();
        for(i=1;i<=n;i++)
        {
            scan_d(x);
            mop[x]++;
        }
        for(i=1;i<=m;i++)
        {
            scan_d(x);
            if(mop.find(x)!=mop.end())
            {
                printf("%d\n",mop[x]);
                mop[x]=0;
            }
            else printf("0\n");
        }
    }
    return 0;
}
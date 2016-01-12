/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11473308
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <ctime>
using namespace std;

#define LL long long
#define ULL unsigned long long
//#define mod 1000000007
#define eps 1e-8
#define MP make_pair
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define RREP(i,a,b) for(int i = b; i >= a ; --i)
#define RE freopen("in.txt","r",stdin)
#define WE freopen("out.txt","w",stdout) 
#define LL long long 

int bitsum(LL x)
{
    int sum=0;
    int a=10,cnt=0;
    while(x>0)
    {
        cnt++;
        if(cnt%2==1)
            sum+=x%10;
        else
            sum-=x%10;
        x/=10;
    }
    return sum;
}
int main()
{
    //RE;
    LL l,r;
    int T;
    scanf("%d",&T);
    LL j;
    while(T--)
    {
        int flag=0;
        scanf("%I64d%I64d",&l,&r);
        for(j=l;j<r;j++)
            if(j%11==3) break;
        for(;j<=r;j+=11)
        {
            if(bitsum(j)!=3&&j%11==3)
            {
                break;
            }
        }
        if(j>r) puts("-1");
        else printf("%I64d\n",j);
    }    
    return 0;
} 
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11695034
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
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define RREP(i,a,b) for(int i = b; i > a ; --i)
#define RE freopen("in.txt","r",stdin)
#define WE freopen("out.txt","w",stdout) 

int main()
{
    int T;
    scanf("%d",&T);
    for(int m=1;m<=T;m++)
    {
        int n;
        scanf("%d",&n);
        double sum=0;
        double k,c;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&k);
            sum+=k;
        } 
        for(int i=0;i<n;i++)
            scanf("%lf",&c);
        printf("Case #%d: %.6lf\n",m,(double)(n+1)/(double)sum);
    } 
} 
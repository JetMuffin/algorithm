/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11329443
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define MAX 805
#define MOD 3
using namespace std;
int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
void mul(int n)
{
    int i,j,k;
    memset(c,0,sizeof(c));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            for(k=0;k<n;k++)
                c[i][k]=(c[i][k]+a[i][j]*b[j][k])%MOD;
        }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {scanf("%d",&a[i][j]);a[i][j]%=MOD;}
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {scanf("%d",&b[i][j]);b[i][j]%=MOD;}
        mul(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(j==0) printf("%d",c[i][j]);
            else printf(" %d",c[i][j]);
            printf("\n");
        }
    }
    return 0;
}
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=12346538
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100005;
int a[maxn],b[maxn];
int f[maxn * 2];
int v[maxn * 2];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(f,0,sizeof(f));
        memset(v,0,sizeof(v));
        scanf("%d",&n);
        for(int i = 0 ; i <n ; i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            f[i] = a[i];
            f[i+n] = b[i];
        }
        sort(f,f+n*2);
        for(int i = 0; i < n ; i++)
        {
                int aa = lower_bound(f, f+2*n,a[i])-f;
                int bb = lower_bound(f, f+2*n, b[i])-f;
                v[aa]++;
                v[bb+1]--;
        }
        int tmp = 0,ans= 0;
        for(int i = 0 ; i < n*2;i++)
        {
            tmp += v[i];
            ans = max(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}
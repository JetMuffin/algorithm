/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13041241
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define LL long long
#define MAXN 100005
int x[MAXN];
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 0 ; i < n ; i++)
    {
      scanf("%d",&x[i]);
    }
    sort(x,x+n);
    LL ans = 0;
    for(int i = 0; i < n; i++)
    {
      int b = upper_bound(x + i + 1, x + n, x[i] + k) - x - i - 1;
      // cout<<b<<endl;
      ans += b; 
    }
    cout<<ans<<endl;
  }
}
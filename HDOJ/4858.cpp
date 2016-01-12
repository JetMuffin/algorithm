/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11295167
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn=110000;
vector<int> g[maxn];
int n,m;
int du[maxn];

int main()
{
  int T_T;
  scanf("%d",&T_T);
  while(T_T--)
  {
     scanf("%d%d",&n,&m);
     for(int i=0;i<=n+10;i++)
       g[i].clear(),du[i]=0;
     for(int i=0;i<m;i++)
     {
       int a,b;
       scanf("%d%d",&a,&b);
       g[a].push_back(b);
       g[b].push_back(a);
     }
     int q;
     scanf("%d",&q);
     while(q--)
     {
       int c,a,b;
       scanf("%d",&c);
       if(c==0)
       {
         scanf("%d%d",&a,&b);
         du[a]+=b;
       }
       else
       {
         scanf("%d",&a);
         int ret=0;
         for(int i=0,sz=g[a].size();i<sz;i++)
           ret+=du[g[a][i]];
         printf("%d\n",ret);
       }
     }
  }
  return 0;
}
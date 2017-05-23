/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14098749
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
using namespace std;
#define LL long long
const int maxn = 100005;
const int mod = 1000000007;
const int N = 10001;
int f[maxn];
int l[maxn];
int r[maxn];
int vis[maxn];
vector<int> fa[10010]; 

int main(){
  int n;
  for(int i=1;i<=10000;i++)  
    {  
        for(int j=1;j<=i;j++)  
        {  
            if(i%j==0)  
            {  
                fa[i].push_back(j);   
            }   
        }   
        //printf("%d\n",my[i].size());  
    }   
  while(~scanf("%d",&n)){
    int cnt = 0;
    memset(vis,0,sizeof(vis));
    // m.clear();
    for(int i = 1 ; i <= n; i++){
      scanf("%d",f+i);
    }
    LL ans = 0;
    for(int i = 1 ; i <= n; i++){
      l[i] = 1;
      for(int k = 0; k < fa[f[i]].size();k++ ){
        int j = fa[f[i]][k];
        if(vis[j] && f[i] % j == 0){
          // cout<<i<<" "<<f[i]<<" "<<j<<" "<<vis[j]<<" @"<<endl;
          int t = i - vis[j] - 1;
          if(t < i - l[i])
            l[i] = vis[j] + 1;
        }    
      }   
      vis[f[i]] = i;
    }
    memset(vis,0,sizeof(vis));
    for(int i = n ; i > 0; i--){
      r[i] = n;
      for(int k = 0; k < fa[f[i]].size();k++ ){
        int j = fa[f[i]][k];
        if(vis[j]){
          if(f[i] % j == 0){
            // cout<<f[i]<<" "<<j<<" "<<"#"<<endl;
            int t = vis[j] - i - 1;
            if(t < r[i] - i )
              r[i] = vis[j] - 1;
          }
        }
      }
      vis[f[i]] = i;
    }

    // for(int i = 1 ; i <= n; i++){
    //   cout<<l[i]<<" "<<i<<" "<<r[i]<<endl;
    // }
    for(int i = 1 ; i <= n; i++){
      ans = (ans + (i - l[i]  + 1) * (r[i] - i + 1) )% mod;
    }    
    printf("%lld\n",ans);
  }
}
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13844638
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
int f[51][51];
int r[51];
int c[51];
using namespace std;
int main(){
  int n,m;
  while(~scanf("%d%d",&n,&m)){
    memset(r,0,sizeof(r));
    memset(c,0,sizeof(c));
    for(int i = 0 ; i < n ; i++){
      for(int j = 0; j < m ; j++){
        scanf("%d",&f[i][j]);
        r[i] += f[i][j];
        c[j] += f[i][j];
      }
    }
    int ans = 0;
    for(int i = 0 ; i < n; i++){
      int flag = 1;
      for(int j = 0 ; j < m; j++){
        if(f[i][j] < (double)c[j]/(double)n){
          flag = 0;
          break;
        }
      }
      if(flag)
        ans++;
    }
    for(int i = 0 ; i < n; i++){
      if(i == 0)
        printf("%.2lf",(double)r[i]/(double)m);
      else
        printf(" %.2lf",(double)r[i]/(double)m);
    }
    printf("\n");
    for(int i = 0 ; i < m; i++){
      if(i == 0)
        printf("%.2lf",(double)c[i]/(double)n);
      else
        printf(" %.2lf",(double)c[i]/(double)n);
    }
    printf("\n");
    printf("%d\n\n",ans);
  }
}

/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13844147
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int m[31][31];
int main(){
  int n;
  while(~scanf("%d",&n)){
    int ans = 0;
    for(int i = 0 ; i < n; i++)
      for(int j = 0 ; j < n; j++){
        int t;
        scanf("%d",&t);
        if(t)
          ans++;
      }
    ans += n*2;
    printf("%d\n",ans);
  }
}
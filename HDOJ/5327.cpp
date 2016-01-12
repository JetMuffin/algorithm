/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14285186
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 100005;
int f[maxn];
int a[10];
int check(int n){
  memset(a,0,sizeof(a));
  while(n){
    int t = n%10;
    n /= 10;
    a[t] ++;
    if(a[t] >= 2){
      return 0;
    }
  }
  return 1;
}
int main(){
  f[0] = 0;
  for(int i = 1; i <= maxn; i++)
    if(check(i))
      f[i] = f[i-1] + 1;
    else
      f[i] = f[i-1];
  int t;
  cin>>t;
  while(t--){
    int a,b;
    cin>>a>>b;
    cout<<f[b]-f[a-1]<<endl;
  }
}
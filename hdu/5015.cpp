/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13948529
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int mod = 10000007;
struct matrix
{
  long long m[15][15];
  matrix()  
  {  
      memset(m,0,sizeof(m));  
  } 
};
int n,m;
void print(matrix a){
  printf("-----------------\n");
  for(int i = 1; i <= n+2; i++)
  {
    for(int j = 1; j <= n+2; j++)
      cout<<a.m[i][j]<<" ";
    printf("\n");
  }
  printf("-----------------\n");
}

matrix mul(matrix a, matrix b){
  matrix c;
  for(int i = 1 ; i <= n+2; i++)
    for(int j = 1; j <= n+2; j++)
    {
      for(int k = 1; k <= n+2; k++)
      {
        c.m[i][j] = (c.m[i][j] + a.m[i][k]*b.m[k][j] ) %mod;
      }
    }
  return c;
} 
matrix pow(matrix a, int k){
  matrix b;
  for(int i = 1; i <= n+2; i++)
    b.m[i][i] = 1;
  while(k >= 1){
    // cout<<k<<endl;
    if(k&1)
      b = mul(b,a);
    a = mul(a,a);
    k = k/2;
  }
  return b;
}

int main(){
  while(~scanf("%d%d",&n,&m)){
    matrix ans,base;
    ans.m[1][1]=23;  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d",&ans.m[i+1][1]);  
    }  
    ans.m[n+2][1]=3;  
    for(int i=1;i<=n+1;i++)base.m[i][1]=10;  
    for(int i=1;i<=n+2;i++)base.m[i][n+2]=1;  
    for(int i=2;i<=n+1;i++)  
    {  
        for(int j=2;j<=i;j++)base.m[i][j]=1;  
    }  
    // print(base);
    base = pow(base,m);
    // print(base);
    ans = mul(base,ans);
    // print(ans);
    cout<<ans.m[n+1][1]<<endl; 
  }
}
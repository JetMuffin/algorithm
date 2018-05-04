#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int x,m,k,c,mod;
struct matrix
{
  long long m[15][15];
  matrix()  
  {  
      memset(m,0,sizeof(m));  
  } 
};

matrix mul(matrix a, matrix b){
  matrix c;
  for(int i = 1 ; i <= 3; i++)
    for(int j = 1; j <= 3; j++)
    {
      for(int k = 1; k <= 3; k++)
      {
        c.m[i][j] = (c.m[i][j] + a.m[i][k]*b.m[k][j] ) %mod;
      }
    }
  return c;
} 
matrix pow(matrix a, int k){
  matrix b;
  for(int i = 1; i <= 3; i++)
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
	int t, cas = 0;
	scanf("%d", &t);
	while(t--) {
		cas++;
		printf("Case #%d:\n", cas);
		scanf("%d%d%d%d", &x, &m, &k, &c);
		matrix a,b;
		mod = k;
		for(int i = 1; i <= 3; i++) {
			for(int j = 1; j <= 3; j++) {
				a.m[i][j] = 0;
			}
		}
		a.m[1][1] = 10;
		a.m[1][3] = a.m[2][1] = a.m[3][3] = 1;
		b.m[1][1] = 10*x+x;
		b.m[2][1] = x;
		b.m[3][1] = x;
		a = pow(a, m-1);
		b = mul(a, b);
		if(b.m[2][1]%k == c) {
			puts("Yes");
			continue;
		} else {
			puts("No");
		}
	}
}
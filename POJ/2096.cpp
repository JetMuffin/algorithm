#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
double dp[1010][1010];
int n,s;
int main(){
  while(~scanf("%d%d",&n,&s)){
	memset(dp,0,sizeof(dp));
	dp[n][s] = 0.0;
	for(int i = n; i >= 0; i--){
	  for(int j = s ; j >= 0; j--){
		if(i == n && j == s)
		  continue;
		double p1 = (i*j)/(double)(n*s);
		double p2 = (n-i)*j/(double)(n*s);
		double p3 = i*(s-j)/(double)(n*s);
		double p4 = (n-i)*(s-j)/(double)(n*s);
		dp[i][j] = (p2*dp[i+1][j] + p3*dp[i][j+1] + p4*dp[i+1][j+1] + 1)/(1-p1);
	  }
	}
	printf("%.4f\n",dp[0][0]);
  }
}

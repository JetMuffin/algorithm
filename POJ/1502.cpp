#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 100000000  
const int maxn = 105;
int g[maxn][maxn];
int min(int a,int b){
	return a<b?a:b;
}

void floyd(int n ){
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				g[i][j] = INF;
		for(int i = 2; i <= n; i++)
			for(int j = 1; j < i; j++){
				int x;
				if(scanf("%d",&x))  g[i][j] = g[j][i] = x;
				else scanf("x"); //input handle
			}
		floyd(n);

		int ans = -1;
		for(int i = 1; i <= n; i++){
			if(g[1][i] > ans)
				ans = g[1][i];
		}
		printf("%d\n",ans);
	}
}
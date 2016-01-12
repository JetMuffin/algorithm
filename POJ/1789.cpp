#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int g[2010][2010];
char s[2010][7];
int vis[2010];
int dis[2010];
int n;
int ans;
const int INF = 100000000;
void prim(){
	memset(vis, 0, sizeof(vis));
	for(int i = 0 ; i < n; i++){
		dis[i] = g[i][0];
	}
	dis[0] = 0;
	vis[0] = 1;
	ans = 0;
	for(int i = 1; i < n; i++){
		int minlen = INF;
		int minpos = -1;
		for(int j = 0; j < n; j++){
			if(!vis[j] && dis[j] < minlen){
				minlen = dis[j];
				minpos = j;
			}
		}
		ans += minlen;
		vis[minpos] = 1;
		for(int j = 0; j < n; j++){
			if(!vis[j] && dis[j] > g[j][minpos]){
				dis[j] = g[j][minpos];
			}
		}
	}
}
int main(){
	while(~scanf("%d",&n)){
		if(n == 0)
			break;
		for(int i = 0 ; i < n; i++)
			scanf("%s",s+i);
		for(int i = 0; i < n-1; i++){
			for(int j = i+1; j < n; j++){
				int cnt = 0;
				for(int k = 0; k < 7; k++){
					if(s[i][k] != s[j][k])
						cnt++;
				}
				g[i][j] = cnt;
				g[j][i] = cnt;
			}
		}
		prim();

		printf("The highest possible quality is 1/%d.\n",ans); 
	}
}
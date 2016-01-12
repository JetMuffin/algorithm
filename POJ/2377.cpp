#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int g[2010][2010];
char s[2010][7];
int vis[2010];
int dis[2010];
int n,m;
int ans;
const int INF = 100000000;
void prim(){
	memset(vis, 0, sizeof(vis));
	for(int i = 1 ; i <= n; i++){
		dis[i] = g[i][1];
	}
	dis[1] = 0;
	vis[1] = 1;
	ans = 0;
	for(int i = 2; i <= n; i++){
		int maxlen = -1;
		int maxpos = -1;
		for(int j = 1; j <= n; j++){
			//cout<<dis[j]<<endl;
			if(!vis[j] && dis[j] > maxlen){
				maxlen = dis[j];
				maxpos = j;
			}
		}
		//cout<<maxlen<<endl;
		if(maxlen == -1){
			ans = -1;
			return; 
		}
		
		ans += maxlen;
		vis[maxpos] = 1;
		for(int j = 1; j <= n; j++){
			if(!vis[j] && dis[j] < g[maxpos][j]){
				dis[j] = g[maxpos][j];
			}
		}
	}
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(g, -1, sizeof(g));
		for(int i = 0 ; i < m; i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if(w > g[u][v]){
				g[u][v] = w;
				g[v][u] = w;				
			}
		}
		prim();
		printf("%d\n",ans);
	}
}
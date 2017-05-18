#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define INF 0x7FFFFFFF   
const int maxn = 150;
vector <pair<int, int> > g[maxn];
int dis[maxn];
int vis[maxn];
void spfa(int n){
    for(int i = 1 ; i <= n; i++){
        dis[i] = INF;
    }
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    dis[1] = 0;
    vis[1] = 1;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i].first;
            int w = g[u][i].second;
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                if(vis[v] == 0){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),m+n){
        for(int i = 0; i < n; i++)
            g[i].clear();
        for(int i = 1; i <= m; i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        spfa(n);
        printf("%d\n",dis[n]);
    }
}
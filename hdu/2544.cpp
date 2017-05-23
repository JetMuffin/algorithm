/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14722091
*/

#include <iostream>
#include <cstdio>
using namespace std;

#define INF 0x3f3f3f3f  
typedef struct Edge{
    int u,v;
    int w;
}Edge;

Edge edge[10010];
int dis[110];

bool Bellman_Ford(int n, int m){
    for(int i = 1; i <= n; i++){
        dis[i] = INF;
    }
    dis[1] = 0;
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= m; j++){

            if( dis[edge[j].u] > dis[edge[j].v] + edge[j].w)
                dis[edge[j].u] = dis[edge[j].v] + edge[j].w;
            
            if( dis[edge[j].v] > dis[edge[j].u] + edge[j].w)
                dis[edge[j].v] = dis[edge[j].u] + edge[j].w;
                
        }
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),m+n){
        for(int i = 1; i <= m; i++)
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        Bellman_Ford(n,m);
        printf("%d\n",dis[n]);
    }
}
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14809876
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
const int maxn = 10010;
vector <int> g[maxn];
LL w[maxn];
int vis[maxn];
int deg[maxn];
LL ans = 0;
LL sum = 0;
int cnt = 0;
void dfs(int x){
    if(vis[x])
        return;
    vis[x] = 1;
    int len = g[x].size();
    // cout<<x<<" "<<sum<<" "<<cnt<<endl;
    sum += w[x];
    cnt++;
    for(int i = 0; i < len; i++){
        int v = g[x][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}
void work(int n){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(deg[i] < 2){
            vis[i] = 1;
            q.push(i);
        }   
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int len = g[u].size();
        for(int i = 0 ; i < len; i++){
            int v = g[u][i];
            if(!vis[v]){
                deg[v] --;
                if(deg[v] < 2){
                    vis[v] = 1;
                    q.push(v);
                }                
            }
        }
    }

}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        memset(vis, 0 , sizeof(vis));
        memset(deg,0, sizeof(deg));
        memset(g,0, sizeof(g));
        ans = 0;
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++)
            scanf("%lld",w+i);
        for(int i = 1; i <= m; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        work(n);
        // for(int i = 1; i <= n; i++)
        //     cout<<vis[i]<<" ";
        // cout<<endl;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                cnt = 0;
                sum = 0;
                dfs(i);
                if(cnt%2 == 1)
                    ans += sum;
            }
        }
        printf("%lld\n",ans);
    }
}

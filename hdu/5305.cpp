/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14138622
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <ctime>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define MP make_pair

#define mod 1000000007
#define eps 1e-8
#define pi acos(-1.0)
#define inf 0x3fffffff
int n,m;
struct edge{
    int u,v;
}e[100];
int deg[10];
int c1[10];
int c2[10];
int ans = 0;
void dfs(int cur){
//    cout<<"cur: "<<cur<<endl;
//    for(int i = 1; i <= n; i ++){
//        cout<<c1[i]<<" ";
//    }
//    cout<<endl;
//    for(int i = 1; i <= n; i ++){
//        cout<<c2[i]<<" ";
//    }
//    cout<<endl;    
    if(cur == m+1){
        ans++;
        return;
    }
    int v = e[cur].v;
    int u = e[cur].u;
    if(c1[u] && c1[v]){
        c1[u] --;
        c1[v] --;
        dfs(cur+1);
        c1[u] ++;
        c1[v] ++;
    }
    if(c2[u] && c2[v]){
        c2[u] --;
        c2[v] --;
        dfs(cur+1);
        c2[u] ++;
        c2[v] ++;
    }
    return;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        ans = 0;
        memset(deg,0,sizeof(deg));
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i = 1; i <=m; i++){
            scanf("%d%d",&e[i].u,&e[i].v);
            deg[e[i].v]++;
            deg[e[i].u]++;
        }    
        int flag = 1;
        for(int i = 1; i <= n; i++){
            if(deg[i] & 1){
                flag = 0;
                break;
            }
            c1[i] = deg[i]/2;
            c2[i] = deg[i]/2;
        }
        if(!flag){
            puts("0");
            continue;
        }
        dfs(1);
        printf("%d\n",ans);
    }
} 
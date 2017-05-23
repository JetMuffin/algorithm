/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=12641979
*/

#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;  
  
const int N = 105;  
  
int n, m, du[N];  
vector<int> g[N];  
  
int main() {  
    while (~scanf("%d%d", &n, &m)) {  
    int u, v;  
    for (int i = 1; i <= n; i++) g[i].clear();  
    memset(du, 0, sizeof(du));  
    while (m--) {  
        scanf("%d%d", &u, &v);  
        g[v].push_back(u);  
        du[u]++;  
    }  
    queue<int> Q;  
    for (int i = 1; i <= n; i++)  
        if (du[i] == 0) Q.push(i);  
    while (!Q.empty()) {  
        int u = Q.front();  
        Q.pop();  
        for (int i = 0; i < g[u].size(); i++) {  
        int v = g[u][i];  
        du[v]--;  
        if (du[v] == 0) Q.push(v);  
        }  
    }  
    int flag = 1;  
    for (int i = 1; i <= n; i++) if (du[i]) flag = 0;  
    printf("%s\n", flag ? "YES" : "NO");  
    }  
    return 0;  
}  
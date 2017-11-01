#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1505;
int head[maxn], cnt;
struct edge {
    int to, next;
}e[maxn * maxn / 2];
int dp[maxn][2];
void add(int u, int v) {
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int u, int fa) {
    dp[u][0] = 0;
    dp[u][1] = 1;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            dfs(v, u);
            dp[u][0] += dp[v][1];
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }
    }
}
int main() {
    int n, u, num, v, rt;
    while(~scanf("%d", &n)) {
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 0; i < n; i++) {
            scanf("%d:(%d)", &u, &num);
            if(i == 0) rt = u;
            for(int j = 0; j < num; j++) {
                scanf("%d", &v);
                add(u, v);
                add(v, u);
            }
        }
        if (n == 1) {
            puts("1");
            continue;
        }
        memset(dp, 0, sizeof(dp));
        dfs(rt, -1);
        printf("%d\n", min(dp[rt][0], dp[rt][1]));
    }
}

/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13871428
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
#define LL long long
const int maxn = 100005;
LL col[maxn<<2];  
LL sum[maxn<<2];
void pushup(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void pushdown(int rt,int m){
    if (col[rt]) {  
        col[rt<<1] = col[rt<<1|1] = col[rt];  
        sum[rt<<1] = (m - (m >> 1)) * col[rt];  
        sum[rt<<1|1] = (m >> 1) * col[rt];  
        col[rt] = 0;  
    } 
}
void build(int l,int r, int rt){
    col[rt] = 0;
    if(l == r){
        sum[rt] += 1;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int L,int R,int c,int l,int r,int rt){
    if(L <= l && r <=R){
        col[rt] = c;
        sum[rt] = (LL)c * (r - l + 1);
        return;
    }
    pushdown(rt,r - l + 1);
    int m = (l+r) >> 1;
    if(L <= m) update(L, R, c, lson);
    if(m < R) update(L, R, c, rson);
    pushup(rt);
}
LL query(int L,int R,int l, int r, int rt){
    if(L <= l && r <=R){
        return sum[rt];
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    LL ret = 0;
    if(L <= m) ret += query(L, R, lson);
    if(m < R) ret += query(L, R, rson);
    return ret;
}
int main(){
    
    int t;
    scanf("%d",&t);
    int cnt = 0;
    while(t--){
        cnt++;
        memset(sum,0,sizeof(sum));
        memset(col,0,sizeof(col));
        int n,m;
        scanf("%d",&n);
        scanf("%d",&m);
        build(root);
        char op[5];
        int a,b,c;
        for(int i = 0 ; i < m; i++){
            scanf("%d%d%d",&a,&b,&c);
            update(a,b,c,root);
        }
        printf("Case %d: The total value of the hook is %d.\n",cnt,query(1,n,root));
    }
    return 0;
}
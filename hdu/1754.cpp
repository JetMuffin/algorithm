/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13871338
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
#define LL long long

const int maxn = 200005;
LL tree[maxn<<2];

void pushup(int rt){
    tree[rt] = max(tree[rt<<1],tree[rt<<1|1]);
}
void build(int l,int r,int rt){
    if(l == r){
        scanf("%d",&tree[rt]);
        return ;  
    }
    int m = (l+r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p ,int v, int l, int r, int rt){
    if(l == r){
        tree[rt] = v;
        return; 
    }
    int m = (l + r) >> 1;
    if(p <= m)
        update(p, v, lson);
    else
        update(p, v, rson);
    pushup(rt);
}
int query(int L, int R, int l, int r, int rt){
    if(L <= l && r <= R){
        return tree[rt];
    }
    int m = (l + r) >> 1;
    int ret = -1;
    if(L <= m)
        ret = max(ret, query(L, R, lson));
    if(m < R)
        ret = max(ret, query(L, R, rson));
    return ret;
}
int main(){
    int m,n;
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)){
        build(root);
        for(int i = 0; i < m; i++){
            char op[2];
            scanf("%s",op);
            int a,b;
            if(op[0] == 'Q'){
                scanf("%d%d",&a,&b);
                printf("%d\n",query(a,b,root));
            } else{
                scanf("%d%d",&a,&b);
                update(a,b,root);
            }
        } 
    }
}
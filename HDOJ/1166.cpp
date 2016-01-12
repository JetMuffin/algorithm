/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13861337
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
LL add[maxn<<2];
LL sum[maxn<<2];
void pushup(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void pushdown(int rt,int m){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += add[rt] * (m-(m>>1));
        sum[rt<<1|1] += add[rt] * (m>>1);
        add[rt] = 0;
    }
}
void build(int l,int r, int rt){
    add[rt] = 0;
    if(l == r){
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void insert(int i,int v,int l, int r, int rt){
    if(l == r && l == i){
        sum[rt] = v;
        return;
    }
    int m = (l + r) >> 1;
    if(i <= m)
        insert(i,v,lson);
    else
        insert(i,v,rson);
    pushup(rt);
}
void update(int L,int R,int c,int l,int r,int rt){
    if(L <= l && r <=R){
        add[rt] += c;
        sum[rt] += (LL)c * (r - l + 1);
        return;
    }
    pushdown(rt,r - l + 1);
    int m = (l+r) >> 1;
    if(L <= m) update(L, R, c, lson);
    if(m < R) update(L, R, c, rson);
    pushup(rt);
}
void updatep(int p, int add, int l, int r, int rt)  
{  
    if( l == r )  
    {  
        sum[rt] += add;  
        return ;  
    }  
    int m = ( l + r ) >> 1;  
    if(p <= m)  
        updatep(p, add, lson);  
    else  
        updatep(p, add, rson);  
  
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
        memset(add,0,sizeof(add));
        printf("Case %d:\n",cnt);
        int n;
        scanf("%d",&n);
        build(root);
        for(int i = 0 ; i < n; i++){
            int temp;
            scanf("%d",&temp);
            insert(i+1,temp,root);
        }
        char op[5];
        int a,b;
        while(scanf("%s",op)){
            if(op[0] == 'Q'){
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(a,b,root));
            }else if(op[0] == 'A'){
                scanf("%d%d",&a,&b);
                updatep(a,b,root);
            }else if(op[0] == 'S'){
                scanf("%d%d",&a,&b);
                b = -b;
                updatep(a,b,root);
            }else{
                break;
            }            
        }

    }
    return 0;
}
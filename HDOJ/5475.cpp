/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14948137
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
using namespace std;
const int maxn = 100010;
LL mul[maxn * 4];
LL m;
LL num[maxn];
LL ops[maxn];
void build(int l, int r, int root){
    if(l == r){
        if(ops[l] == 1)
            mul[root] = num[l];
        else
            mul[root] =1;
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, root*2);
    build(mid+1, r, root*2+1);
    mul[root] = (mul[root*2]*mul[root*2+1])%m;
}
void update(int a, int b, int l, int r, int root){
    if(r<a || l > a){
        return;
    }
    if(r == l){
        mul[root] = b;
        return;
    }
    int mid = (l+r)/2;
    update(a,b,l,mid,root*2);
    update(a,b,mid+1,r,root*2+1);
    mul[root] = (mul[root*2]*mul[root*2+1])%m; 
}

LL query(int ql, int qr, int l, int r, int root){
    if(l > qr || r < ql)
        return 1;
    if(ql <= l && r <= qr){
        return mul[root];
    }
    int mid = (l+r)/2;
    return (query(ql, qr, l, mid, root*2)*query(ql, qr, mid+1, r, root*2+1))%m;
}

int main(){
    int t;
    int caset = 0;
    scanf("%d",&t);
    while(t--){
        caset++;
        printf("Case #%d:\n", caset);
        LL q;
        int cnt = 0;
        scanf("%lld%lld",&q,&m);
        for(int i = 1 ; i <= q; i++){
            LL op,y;
            scanf("%lld%lld",&op,&y);
            num[i] = y;
            ops[i] = op; 
        }
        build(1,q,1);
        LL ans = 1;
        for(int i = 1 ; i <= q; i++){
            if(ops[i] == 1){
                ans =  ans*num[i]%m;
                printf("%lld\n", ans);
            }else{
                update(num[i],1,1,q,1);
                ans = query(1,i,1,q,1);
                printf("%lld\n", ans);                   
            }
        }
    }
}
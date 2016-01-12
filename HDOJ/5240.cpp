/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13824266
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 100005
struct exam{
    int r,e,l;
}f[maxn];
int cmp(exam a,exam b){
    return a.e < b.e;
}
int main(){
    int t;
    scanf("%d",&t);
    int cnt = 0;
    while(t--){
        memset(f,0,sizeof(f));
        cnt ++;
        int n;
        int flag = 1;
        scanf("%d",&n);
        for(int i = 0 ; i < n; i++){
            scanf("%d%d%d",&f[i].r,&f[i].e,&f[i].l);
        }
        sort(f,f+n,cmp);
        for(int i = 0 ; i < n - 1; i++){
            if(f[i].r > f[i].e){
                flag = 0;
                break;
            }
            f[i+1].r += f[i].r + f[i].l;
        }
        if(f[n-1].r > f[n-1].e)
            flag = 0;
        if(!flag)
            printf("Case #%d: NO\n",cnt);    
        else
            printf("Case #%d: YES\n",cnt);
    }    
}

/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14809887
*/

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1005;
int a[maxn];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 1 ; i <= n; i++)
            scanf("%d",a+i);
        int q;
        scanf("%d",&q);
        for(int i = 1 ; i <= q; i++){
            int l,r;
            scanf("%d%d",&l,&r);
            int max = -1;
            for(int j = l; j<=r; j++){
                if(a[j] > max )
                    max = a[j];
            }
            printf("%d\n",max);
        }
    }
}
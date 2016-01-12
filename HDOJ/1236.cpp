/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14708059
*/

#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1015;
int n,m,line;
int sc[15];
struct node{
    string id;
    int s;
}a[maxn];
int cmp(node a, node b){
    if(a.s == b.s){
        return a.id < b.id;
    }
    return a.s > b.s;
}
int main(){
    while(~scanf("%d",&n)){
        if(n == 0)
            break;
        scanf("%d%d",&m,&line);
        for(int i = 1 ; i <= m; i++)
            scanf("%d",sc+i);
        int cnt = 0;
        for(int i = 0 ; i < n; i++){
            cin>>a[i].id;
            a[i].s = 0;
            int num;
            scanf("%d",&num);
            for(int j = 0 ; j < num; j++){
                int t;
                scanf("%d",&t);
                a[i].s += sc[t];
            }
            if(a[i].s >= line)
                cnt++;
        }
        printf("%d\n",cnt);
        sort(a,a+n,cmp);
        for(int i = 0; i < cnt; i++){
            cout<<a[i].id<<" ";
            printf("%d\n",a[i].s);
        }
    }
}
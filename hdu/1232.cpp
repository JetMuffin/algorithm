/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14707676
*/

#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 10005;
int pre[maxn],top[maxn];
void init(int n){
    for(int i = 1 ; i <= n; i++){
        pre[i] = i;
        top[i] = 1;
    }
}
int find(int x){
    if(x != pre[x])
        pre[x] = find(pre[x]);
    return pre[x];        
}
void merge(int x, int y){
    int a = find(x);
    int b = find(y);
    if(top[a] < top[b]){
        pre[a] = b;
        top[b] += top[a];
    }else{
        pre[b] = a;
        top[a] += top[b];
    }
}
int main(){
    int n,m;
    while(~scanf("%d",&n)){
        if(n == 0)
            break;
        scanf("%d",&m);
        init(n);
        for(int i = 0 ; i < m; i++){
            int x, y;
            scanf("%d%d",&x,&y);
            merge(x,y);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(pre[i] == i)
                cnt ++;
        }
        printf("%d\n",cnt-1);
    }
}
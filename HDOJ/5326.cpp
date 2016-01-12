/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14284736
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

#define MAXN 400
int pre[MAXN];
int a[MAXN];

void combine(int i,int j){
    pre[j] = i;
    a[i]++;
    while(pre[i] != -1){
        a[pre[i]]++;
        i = pre[i];
    }
}

int main(){
    int n,k;
    while(scanf("%d%d",&n,&k) != EOF){
        memset(pre,-1,sizeof(pre));
        memset(a,0,sizeof(a));
        int x,y;
        for(int i=0; i<n-1; i++){
            scanf("%d%d",&x,&y);
            combine(x,y);
        }

        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(a[i] == k)
                cnt++;
        }
        cout<<cnt<<endl;

        // for(int i=1; i<=n; i++)
        //     a[i].clear();
    }
    return 0;
} 
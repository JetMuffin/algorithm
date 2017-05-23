/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11201136
*/

#include<iostream>
#include<algorithm>
using namespace std;
int f[1000000];
int cmp(int a,int b){return a>b;}
int main(){
    __int32 m,n;
    __int32 i;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&f[i]);
        sort(f,f+n,cmp);
        for(i=0;i<m;i++)
            if(i==0)
                printf("%d",f[i]);
            else 
                printf(" %d",f[i]);
        printf("\n");
    }
    return 0;
}
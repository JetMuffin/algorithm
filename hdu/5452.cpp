/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14887655
*/

#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<vector>  
#include<map>  
#include<deque>  
#include<functional>  
#include<iterator>  
#include<set>  
#include<utility>  
#include<stack>  
#include<queue>  
using namespace std;  
#define maxn 22222  
#define inf 1500000007  
int deg1[maxn],deg2[maxn];  
int main()  
{  
    int i,j,k,n,x,y,m,T,p=1;  
    scanf("%d",&T);  
    while(T--)  
    {  
        memset(deg1,0,sizeof(deg1));  
        memset(deg2,0,sizeof(deg2));  
        scanf("%d%d",&n,&m);  
        for(i=1;i<=n-1;++i)  
        {  
            scanf("%d%d",&x,&y);  
            deg1[x]++;  
            deg1[y]++;  
        }  
        for(;i<=m;++i)  
        {  
            scanf("%d%d",&x,&y);  
            deg2[x]++;  
            deg2[y]++;  
        }  
        m=5555555;  
        for(i=1;i<=n;++i)  
        {  
            if(deg1[i] == 1)  
                m = min(m,deg2[i]);  
        }  
        printf("Case #%d: %d\n",p++,m+1);  
    }  
    return 0;  
}  
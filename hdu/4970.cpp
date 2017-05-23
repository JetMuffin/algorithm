/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11496207
*/

#include<iostream>
#include<cstring>
using namespace std;
#define maxn 100001
#define LL long long
LL hp[maxn],att[maxn];
int app[maxn];
void show(int N)
{
        for(int i=1;i<=N;i++)
            cout<<att[i]<<" ";
        cout<<endl;    
}
int main()
{
    //freopen("data.txt","r",stdin);
    int N,M,K;
    int i,j;
    int cnt;
    while(scanf("%d",&N)!=EOF)
    {
        cnt=0;
        memset(att,0,sizeof(att));
        int L,R,D;
        if(!N) break;
        scanf("%d",&M);
        for(i=1;i<=M;i++)
        {
            scanf("%d%d%d",&L,&R,&D);
            att[R]+=D;
            att[L-1]-=D;
        }
        
//        show(N);
        for(i=N-1;i>=1;i--)
            att[i]=att[i]+att[i+1];
        
//        show(N);
        for(i=N-1;i>=1;i--)
            att[i]=att[i]+att[i+1];
        cin>>K;
        for(i=1;i<=K;i++)
            scanf("%I64d%d",&hp[i],&app[i]);
//        show(N);
        for(i=1;i<=K;i++)
            if(hp[i]>att[app[i]]) cnt++;
        printf("%d\n",cnt);
    }
}
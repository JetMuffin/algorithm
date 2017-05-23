/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11623535
*/

/*
**    并查集模板，用并查集解决类亲戚关系问题 
**
*/

#include <iostream>
using namespace std;
#define maxn 10000

int rank[maxn],uset[maxn];

void makeSet(int size)
{
    for(int i=0;i<size;i++)
    {
        rank[i]=0;
        uset[i] = i;
    }
}

int find(int x) {
    if (x != uset[x]) uset[x] = find(uset[x]);
    return uset[x];
}

void unionSet(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    else
    {
        if(rank[x]>rank[y])
            uset[y]=x;
        else
        {
            uset[x]=y;
            if(rank[x]==rank[y]) rank[y]++;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--) 
    {
        memset(rank,0,sizeof(rank));
        memset(uset,0,sizeof(uset));
        int n,m,a,b;
        int cnt=0;
        cin>>n>>m;
        makeSet(n);
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            unionSet(a,b);
        }
        for(int i=0;i<n;i++)
        {
            if(find(i)==i) cnt++;
        }
        cout<<cnt<<endl;
    }
    
}
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11623865
*/


#include <iostream>
#include <cstring>
using namespace std;
#define maxn 100010

int rank[maxn],uset[maxn],vis[maxn];

void makeSet(int size)
{
    for(int i=0;i<size;i++)
    {
        rank[i]=0;
        uset[i] = i;
        vis[i] = 0;
    }
}

int find(int x) {
    if (x != uset[x]) uset[x] = find(uset[x]);
    return uset[x];
}

int unionSet(int x,int y)
{
//    int a = x;
//    int b = y;
    x=find(x);
    y=find(y);
    if(x==y) 
    {
//        cout<<"MERGE CONFLICT:"<<a<<" "<<b<<endl;
        return 1;
    }
    else
    {
        if(rank[x]>rank[y])
            uset[y]=x;
        else
        {
            uset[x]=y;
            if(rank[x]==rank[y]) 
                rank[y]++;    
        }
    }
    return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int a,b;
    makeSet(maxn);
    int cnt=0;
    int flag=0;
    while(cin>>a>>b)
    {
        if(a==-1&&b==-1) return 0;
        if(a==0&&b==0) 
        {
//            for(int i=0;i<9;i++)
//                cout<<find(i)<<" ";
//            cout<<endl;
            for(int i=0;i<maxn;i++)
                if(vis[i]&&find(i)==i) cnt++;
//            cout<<cnt<<endl;
            if(cnt>1) flag =1;
            if(flag) puts("No");
            else puts("Yes");
                    
            memset(rank,0,sizeof(rank));
            memset(uset,0,sizeof(uset));
            makeSet(maxn);
            flag=0;
            cnt=0;
            continue;
        }
        vis[a] = 1;
        vis[b] = 1;
        if(unionSet(a,b)) flag=1;
    }
}
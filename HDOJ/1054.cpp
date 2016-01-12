/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14198870
*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define MAXN 1510
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int n,node[MAXN];
    bool vis[MAXN];
    while(scanf("%d",&n)!=EOF)
    {
        memset(node,0,sizeof(node));
         vector<int>road[MAXN];
        for(int i=0; i<n; i++)
        {
            int a,b,c;
            scanf("%d:(%d)",&a,&b);
            for(int j=0; j<b; j++)
            {
                cin>>c;
                road[a].push_back(c);
                road[c].push_back(a);
                node[a]++;
                node[c]++;
            }
        }
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        queue<int>st;
        for(int i=0; i<n; i++)
            if(node[i]==1)
                st.push(i);
        int sum=0;
        memset(vis,false,sizeof(vis));
        while(!st.empty())
        {
            int u=st.front();
            st.pop();
            if(vis[u])  continue;
            for(int i=0; i<(int)road[u].size(); i++)
            {
                int t=road[u][i];
                if(!vis[t])
                {
                    vis[t]=1;
                    sum++;
                    for(int j=0; j<(int)road[t].size(); j++)
                    {
                        int q=road[t][j];
                        node[q]--;
                        if(node[q]==1&&!vis[q])
                            st.push(q);
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
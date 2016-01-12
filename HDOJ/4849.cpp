/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11187022
*/

#include <iostream>
#include<stack>
__int64 x[1000000],y[1000000],z[1000000],c[1004][1004];
using namespace std;

void DijkstraPath(int n,__int64 *dist,int v0)   
{
    int i,j,k;
    int *visited=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)     
    {
        if(c[v0][i]>0&&i!=v0)
        {
            dist[i]=c[v0][i];
        }
        else
        {
            dist[i]=INT_MAX;    
        }
        visited[i]=false;
        dist[v0]=0;
    }
    visited[v0]=true;
    for(i=1;i<n;i++)     
    {
        int min=INT_MAX;
        int u;
        for(j=0;j<n;j++)    
        {
            if(visited[j]==false&&dist[j]<min)
            {
                min=dist[j];
                u=j;        
            }
        } 
        visited[u]=true;
        for(k=0;k<n;k++)    
        {
            if(visited[k]==false&&c[u][k]>0&&min+c[u][k]<dist[k])
            {
                dist[k]=min+c[u][k];
            }
        }        
    }    
}

int main()
{
    //freopen("data.txt","r",stdin);
    int n,m,e;     
    while(cin>>n>>m>>x[0]>>x[1]>>y[0]>>y[1])
    {
        int i,j;
        int s,t,w;     
        __int64 x0,x1,y0,y1;
        long int min;
        int v0;
        __int64 *dist=(__int64 *)malloc(sizeof(__int64)*n);
        e=n*n-n;
        for(i=0;i<1004;i++)
            for(j=0;j<1004;j++)
                c[i][j]=0;
        
        for(i=2;i<(n*(n-1)+n-1);i++)
        {
             x[i]=(12345+x[i-1]*23456+x[i-2]*34567+x[i-1]*x[i-2]*45678) % 5837501;
             y[i]=(56789+y[i-1]*67890+y[i-2]*78901+y[i-1]*y[i-2]*89012) % 9860381;
        }
        for(i=0;i<n*(n-1)+n-1;i++)
            z[i]=(x[i]*90123 + y[i]) % 8475871 + 1;
    
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(i==j) c[i][j]=0;
                else 
                    c[i][j]=z[i*n+j];
                    
        v0=0;        
        DijkstraPath(n,dist,v0);
        
           
        min=dist[1]%m;
        for(i=2;i<n;i++)
        {
            int di=dist[i]%m;
            if(di<min)
            {
                min=di;
            }
        }
        cout<<min<<endl;
    }
    return 0;
}
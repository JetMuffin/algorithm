/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=12816278
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct node{
    int len;
    int rank;
    int i;
}f[100];
int cmp(node a,node b)
{
    return a.len>b.len; 
}
int cmp2(node a,node b)
{
    return a.i<b.i; 
}
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        memset(f,0,sizeof(f));
        cin>>n; 
        int a,b,c,maxx;
        for(int i = 1; i <= n ; i++)
        {
            cin>>a>>b>>c;
            maxx = max(a,b);
            maxx = max(maxx,c);
            f[i].len = maxx;
            f[i].i = i;
        } 
        sort(f+1,f+1+n,cmp);
        for(int i = 1; i <= n ; i++)
        {
            f[i].rank = i;
        }
        sort(f+1,f+1+n,cmp2);
        for(int i = 1; i <= n; i++)
            if(i!=1)
                cout<<" "<<f[i].rank;
            else
                cout<<f[i].rank;
        cout<<endl;
    }
    
}
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11116261
*/

#include<iostream>
#include<string.h>
using namespace std;
int next[10000];
int s[1000000],p[10000];
void makeNext(int *p,int *next,int m)
{
    int q,k;
    next[0] = 0;
    for(q=1,k=0;q<m;q++)
    {
        while(k>0&&p[q]!=p[k])
            k = next[k-1];
        if(p[q]==p[k])
            k++;
        next[q]=k;
    }
}
int kmp(int *s,int *p,int *next,int n,int m)
{
     int i,q;
     int count = 0;
     makeNext(p,next,m);
     for (i = 0,q = 0; i < n; ++i)
     {
         while(q > 0 && p[q] != s[i])
             q = next[q-1];
         if (p[q] == s[i])
         {
             q++;
         }
         if (q == m)
         {
             return i-m+2;
         }
     }
     return -1;    
}
int main()
{
    int T;
    int i,n,m;
    //freopen("data.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
            cin>>s[i];
        for(i=0;i<m;i++)
            cin>>p[i];
        cout<<kmp(s,p,next,n,m)<<endl;    
    }
}
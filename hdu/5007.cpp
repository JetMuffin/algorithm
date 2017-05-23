/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11654375
*/

#include<iostream>
#include<string.h>
using namespace std;
#define maxn 100000
int next[maxn];
char s[maxn],p[maxn];
void makeNext(char *p,int *next)
{
    int q,k;
    int m = strlen(p);
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
int kmp(char *s,char *p,int *next)
{
     int n,m;
     int i,q;
     int count = 0;
     n = strlen(s);
     m = strlen(p);
     makeNext(p,next);
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
             count++;
         }
     }
     return count;    
}
int check1(char *s)
{
    if(kmp(s,"Apple",next)||kmp(s,"iPhone",next)||kmp(s,"iPod",next)||kmp(s,"iPad",next))
        return 1;
    else return 0;
}
int check2(char *s)
{
    if(kmp(s,"Sony",next)) return 1;
    else return 0;
}
int main()
{
    
    //freopen("in.txt","r",stdin);
    while(cin>>s)
    {
        if(check1(s)) cout<<"MAI MAI MAI!"<<endl;
        if(check2(s)) cout<<"SONY DAFA IS GOOD!"<<endl;    
    }
}
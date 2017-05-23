/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10770779
*/

#include<iostream>
using namespace std;
#define MAXN 3000
int a[MAXN],b[MAXN];
char s[MAXN],t[MAXN];
int main()
{
    int i,T,k,j;
    cin>>T;
    for(k=0;k<T;k++)
    {
            memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(s,0,sizeof(s));
    memset(t,0,sizeof(t));           
    cin>>s;
    for(i=0;i<strlen(s);i++)
        a[i]=s[strlen(s)-i-1]-'0';
    cin>>t;
    for(i=0;i<strlen(t);i++)
        b[i]=t[strlen(t)-i-1]-'0';    
    int c=0;
    for(i=0;i<MAXN;i++)
    {
    
        a[i]=a[i]+b[i]+c;
        if(a[i]>9) 
        {
            c=1;                    
            a[i]-=10;
        }
        else c=0;
    }
    for(i=MAXN-1;i>=0;i--) if(a[i]) break;
    cout<<"Case "<<k+1<<":"<<endl;
    cout<<s;
    cout<<" + ";
    cout<<t;
    cout<<" = ";
    for(j=i;j>=0;j--) cout<<a[j];
    cout<<endl;
    if(k!=T-1) cout<<endl;
    }


    return 0;
}
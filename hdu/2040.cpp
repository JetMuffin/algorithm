/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10916352
*/

#include<iostream>
using namespace std;
#define maxn 600001
int f[maxn]={0};
int main()
{
    int i,n,m,t,j,sum;
    cin>>t;
    for(i=1;i<maxn;i++)
        for(j=2*i;j<maxn;j+=i)
            f[j]+=i;
    while(t--)
    {
        cin>>m>>n;
        if(f[m]==n&&f[n]==m)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
} 
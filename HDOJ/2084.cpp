/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10854831
*/


#include<iostream>
using namespace std;
int a[104][104],f[104][104];
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int i,j,k,n,maxx;
    cin>>k;
    while(k--)
    {
        memset(f,0,sizeof(f));
        cin>>n;
        for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
                cin>>a[i][j];
        maxx=a[1][1];
        for(i=n;i>=1;i--)
            for(j=1;j<=i;j++)
            {
                f[i][j]=a[i][j]+max(f[i+1][j],f[i+1][j+1]);
                maxx=max(f[i][j],maxx);    
            } 
        cout<<maxx<<endl;
    }
}
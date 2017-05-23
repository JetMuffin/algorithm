/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10917693
*/

#include<iostream>
using namespace std;
int f[41];
int main()
{
    int i,t,n;
    f[1]=1;
    f[2]=1;
    for(i=3;i<=40;i++)
        f[i]=f[i-1]+f[i-2];
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<f[n]<<endl;
    }
    return 0;
} 
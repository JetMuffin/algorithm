/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10903561
*/

#include<iostream>
using namespace std;
__int64 f[51];
int main()
{
    int i,n;
    f[0]=0;
    f[1]=1;
    for(i=2;i<=50;i++)
        f[i]=f[i-1]+f[i-2];
    while(cin>>n&&n!=-1)
        cout<<f[n]<<endl;    
    return 0;
}
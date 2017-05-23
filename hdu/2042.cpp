/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10917932
*/

#include<iostream>
using namespace std;
int f[31];
int main()
{
    int n,i,t;
    f[0]=3;
    for(i=1;i<=30;i++)
        f[i]=(f[i-1]-1)*2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<f[n]<<endl;
    }
    return 0;
}
 
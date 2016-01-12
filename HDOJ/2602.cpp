/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10842437
*/

#include<iostream>
using namespace std;
int v[1004],w[1004],f[1004];
int main()
{
    int n,m,i,j,k;
    cin>>k;
    while(k--)
    {
        memset(f,0,sizeof(f));
        cin>>n>>m;
        for(i=1;i<=n;i++)
            cin>>v[i];
        for(i=1;i<=n;i++)
            cin>>w[i];
        for(i=1;i<=n;i++)
        {
            for(j=m;j>=w[i];j--)
            {
                if(f[j]<f[j-w[i]]+v[i])
                    f[j]=f[j-w[i]]+v[i];
            }
        }
        cout<<f[m]<<endl;    
    } 
    return 0;
} 
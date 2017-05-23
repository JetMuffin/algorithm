/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10843691
*/


#include<iostream>
#include<iomanip>
using namespace std;
int w[10004];
double v[10004],f[10004];
int main()
{

    int n,m,i,j,k;
    while(true)
    {
        cin>>m>>n;
        if(n==0&&m==0) break;
        for(i=1;i<=n;i++)
            cin>>w[i]>>v[i];
        for(i=0;i<=m;i++)
            f[i]=1;
        for(i=1;i<=n;i++)
        {
            for(j=m;j>=w[i];j--)
            {
                if(f[j]>f[j-w[i]]*(1-v[i]))
                    f[j]=f[j-w[i]]*(1-v[i]);
            }
        }
        printf("%.1f%%\n",100*(1-f[m]));
    }

    return 0;
} 
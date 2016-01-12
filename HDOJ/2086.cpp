/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10867483
*/

#include<iostream>
using namespace std;
double c[3001];
int main()
{
//    freopen("data.txt","r",stdin);
    int n,i;
    double a0,a1,an,csum=0;
    while(cin>>n)
    {
        csum=0;
        cin>>a0>>an;
        for(i=1;i<=n;i++)
            cin>>c[i];
        for(i=n;i>=1;i--)
            csum+=2*(n-i+1)*c[i];
        a1=(n*a0+an-csum)/(double)(n+1);
        printf("%.2lf\n",a1);
    }

} 
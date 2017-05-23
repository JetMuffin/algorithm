/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10855320
*/

#include<iostream>
using namespace std;
double f[1004];
int main()
{
    int odd=0,i,n,t;
    double sum=0;
    for(i=1;i<1000;i++)
    {
        if(odd)
        {
            sum-=1/(double)i;
            odd=0;
        }
        else {
            sum+=1/(double)i;
            odd=1;
        }
        f[i]=sum;
    }
    cin>>n;
    while(n--)
    {
        cin>>t;
        printf("%.2lf\n",f[t]);    
    }
    return 0;
}
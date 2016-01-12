/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10903553
*/

#include<iostream>
using namespace std;
int main()
{
    int t,n;
    double h,max;
    cin>>t;
    while(t--)
    {
        max=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>h;
            if(h>max) max=h;
        }
        printf("%.2lf\n",max);
    }    
    return 0;
} 
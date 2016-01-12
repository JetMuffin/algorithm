/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10854940
*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int b,c,n;
    double sum,a;
    while(cin>>a>>b)
    {
        sum=0;
        while(b--)
        {
            sum+=a;
            a=sqrt((double)a);
        }
        printf("%.2lf\n",sum);
    }
    return 0;    
} 
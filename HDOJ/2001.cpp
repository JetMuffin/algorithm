/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10854857
*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double a,b,c,d;
    double l;
    while(cin>>a>>b>>c>>d)
    {
        l=sqrt((double)((a-c)*(a-c)+(b-d)*(b-d)));
        printf("%.2lf\n",l);    
    }
            
} 
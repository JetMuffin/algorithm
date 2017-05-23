/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10829629
*/

#include<iostream>
#include<math.h> 
using namespace std;
int main()
{
    int T;
    double k,h,m,b,a,x1,y1,x2,y2,x3,y3,y4,y5,sum=0,i;
    
    cin>>T;
    for(int j=0;j<T;j++)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        
        m=x1;
        h=y1;
        a=(y2-h)/(x2-m)/(x2-m);
        if(x3!=x2)k=(y3-y2)/(x3-x2);
        else k=0;
        b=y2-k*x2;
        
        i=x2;
        while(i<=x3)
        {
            y4=a*(i-m)*(i-m)+h;
            y5=k*i+b;
            sum=sum+fabs(y4-y5)*0.01;
            i+=0.01;    
        }
        printf("%.2f\n",sum);
        sum=0;    
    }
    
    
    return 0;
} 
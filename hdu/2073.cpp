/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10903684
*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double len,change=0,stri,count;
    int a,b,c,d,i,j,temp,sum1,sum2;
    cin>>j;
    while(j--)
    {
        stri=0;
        change=0;
            cin>>a>>b>>c>>d;
    sum1=a+b;
    sum2=c+d;
    if(sum1>sum2)
    {
        count= (a+sum2-c);
        for(i=sum2+1;i<sum1;i++)
            count+=i; 
        stri=count*sqrt(2.0);
    }
    else if(sum1==sum2)
        {
            stri=abs(a-c)*sqrt(2.0);
        }
    else{
        count=(c+sum1-a);
        for(i=sum1+1;i<sum2;i++)
            count+=i; 
        stri=count*sqrt(2.0);
    }
    if(sum1>sum2){temp=sum1;sum1=sum2;sum2=temp;}
    for(i=sum1;i<sum2;i++)
        change+=sqrt((double)(i*i)+(i+1)*(i+1));
    len=change+stri;
    printf("%.3lf\n",len);
    
    }
return 0;
}
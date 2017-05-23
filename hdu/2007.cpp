/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10854919
*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b,c,sum,mul;
    while(cin>>a>>b)
    {
        mul=0;
        sum=0;
               if(a>b)
        {
            c=a;
            a=b;
            b=c;
        }
        for(int i=a;i<=b;i++)
    {
    
        if(i%2!=0)
            mul+=i*i*i;
            else 
                sum+=i*i;
    }    
        cout<<sum<<" "<<mul<<endl;
    }            
} 
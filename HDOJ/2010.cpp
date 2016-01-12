/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10854955
*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b,c,m,n,count;
    while(cin>>m>>n)
    {
        count=0;
        for(int i=m;i<=n;i++)
        {
            a=i%10;
            b=i/10%10;
            c=i/100;
            if(i==a*a*a+b*b*b+c*c*c)
                {    
                    count++;
                    if(count!=1)
                        cout<<" "<<i;
                    else cout<<i;
                }
        }
        if(count==0) cout<<"no";
        cout<<endl;
    }    
} 
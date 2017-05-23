/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10856359
*/

#include<iostream>
using namespace std;
int main()
{
    int i,j,x,y,sum,flag=1;
    while(cin>>x>>y)
    {
        if(x==0&&y==0)break;
        for(i=x;i<=y;i++)
        {
            sum=i*i+i+41;
            for(j=2;j*j<sum;j++)
            {
                if(sum%j==0) {flag=0;break;}
            }
            if(flag==0)break;
        }
        if(flag) cout<<"OK"<<endl;
        else cout<<"Sorry"<<endl;
        flag=1;    
    }
} 
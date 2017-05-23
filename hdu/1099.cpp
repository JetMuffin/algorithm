/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10829867
*/

#include<iostream>
using namespace std;
int main()
{
    int n,i,j,inter;
    __int64 deno,num,a,b,x,temp;
    while(cin>>n)
    {
        num=0,deno=1,inter=1;
        for(i=1;i<n;i++)
        {
            x=i*deno;
            j=i;
            while(j!=0)
            {
            temp=deno%j;
            deno=j;
            j=temp;    
            }
            deno=x/deno;        
        }
        for(i=1;i<n;i++)
        {
            num+=(n*deno/i);
        }
        inter+=(num/deno);
        num%=deno;
        a=deno;
        b=num;
        while(b!=0)
        {
            temp=a%b;
            a=b;
            b=temp;    
        }
        deno/=a;
        num/=a;
        if(num==0) cout<<inter<<endl;
        else{
        a=inter;
        while(a!=0)
        {
            cout<<" ";
            a/=10;
        }
        cout<<" "<<num<<endl;
        cout<<inter<<" ";
        a=deno;
        while(a!=0)
        {
            cout<<"-";
            a/=10; 
        }
        cout<<endl;
        a=inter;
        while(a!=0)
        {
            cout<<" ";
            a/=10;
        }
        cout<<" ";
        cout<<deno<<endl;        
        }    
    }
    return 0;
} 
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10829427
*/

#include<iostream>
using namespace std;
int main()
{
    int a,b,x,y,z,t=99999;
    __int64 n;
    while(cin>>a>>b>>n&&(a!=0||b!=0||n!=0))
    {
        x=y=1;
        if(n==1||n==2) {cout<<1<<endl;}
        else{
            n%=48;
            for(int i=1;i<=n-2;i++)
        {
            z=(a*y+b*x)%7;
            x=y;
            y=z;    
        }
        cout<<z<<endl;
        z=0;
        }
        
    }
    return 0;
}
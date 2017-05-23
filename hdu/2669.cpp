/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11122586
*/

#include<iostream>
using namespace std;
typedef __int64 LL;
LL extgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    LL r = extgcd(b,a%b,x,y);
    LL t = x;
    x = y;
    y = t - a/b*y;
    return r;
}
int main()
{
    LL x,y,a,b;
    while(cin>>a>>b)
    {
        if(extgcd(a,b,x,y)!=1) 
            cout<<"sorry"<<endl;
        else
        {
            if(b<0) b=-b;    //重点，解决负数 ,取非负的x 
            LL ans=x%b;  
            if(ans<=0) ans+=b;  
            cout<<ans<<" "<<(1-ans*a)/b<<endl;
        }

    }
    return 0;
} 
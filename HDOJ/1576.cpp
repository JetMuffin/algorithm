/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11123156
*/

#include<iostream>
using namespace std;
int extgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r = extgcd(b,a%b,x,y);
    int t = x;
    x = y;
    y = t - a/b*y;
    return r;
}
int cal(int a,int b,int c)  
{  
    int x,y;  
    int gcd=extgcd(a,b,x,y);  
    if(c%gcd!=0) return -1;  
    x*=c/gcd;  
    b/=gcd;  
    if(b<0) b=-b;   
    int ans=x%b;  
    if(ans<=0) ans+=b;  
    return ans;  
}  
int main()
{
    int T,n,B,ans;
    cin>>T;
    while(T--)
    {
        cin>>n>>B;
        ans = cal(B,9973,n);
        cout<<ans<<endl;
    }
} 
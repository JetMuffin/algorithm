/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11118682
*/

#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    int temp;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    while(b!=0)
    {
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}
int main()
{
    int a,b,i,T;
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        for(i=2*b;i<a;i+=b)
            if(gcd(a,i)==b) break;
        cout<<i<<endl;        
    }

}
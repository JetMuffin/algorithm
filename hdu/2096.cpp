/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11931802
*/

#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        if(a>=100) a=a%100;
        if(b>=100) b=b%100;
        int sum = a+b;
        if(sum>=100) sum=sum%100;
        cout<<sum<<endl;
    }
}
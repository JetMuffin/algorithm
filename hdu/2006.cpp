/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10854909
*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,a,mul;
    while(cin>>n)
    {
        mul=1;
        for(int i=0;i<n;i++)
    {
            cin>>a;
        if(a%2!=0)
            mul*=a;
    }    
        cout<<mul<<endl;
    }            
} 
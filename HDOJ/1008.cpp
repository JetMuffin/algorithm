/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10777406
*/

#include<iostream>
using namespace std;
int a[100];
int main()
{
    int n,i,sum;
    while(cin>>n&&n!=0)
    {
        sum=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        sum+=a[0]*6;    
        for(i=1;i<n;i++)
            if(a[i]>a[i-1]) sum=sum+(a[i]-a[i-1])*6;
            else sum= sum+(a[i-1]-a[i])*4;
        sum=sum+5*n;
        cout<<sum<<endl;
    }
        
    return 0;
} 
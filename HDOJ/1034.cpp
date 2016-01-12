/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10803820
*/

#include<iostream>
using namespace std;
#define MAXN 100
int a[MAXN],b[MAXN];
int main()
{
    int n,i,flag,count;
    while(cin>>n&&n!=0)
    {
        flag=0,count=0;
            for(i=0;i<n;i++)
        cin>>a[i];
    
        while(!flag)
        {
        for(i=0;i<n;i++)
        {
            b[i]=a[i]/2;
            a[i]/=2;
        }
        for(i=0;i<n-1;i++)
        {
            a[i+1]+=b[i];
            if(a[i+1]%2!=0) a[i+1]++;            
        }
        a[0]+=b[i];
        if(a[0]%2!=0) a[0]++;
        for(i=0;i<n;i++)
            if(a[i]!=a[0]) break;
        if(i==n) flag=1;
        count++;
    }
    cout<<count<<" "<<a[0]<<endl;
    
    }
return 0;
} 


    
    

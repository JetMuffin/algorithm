/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10856526
*/

#include<iostream>
using namespace std;
int a[100];
int main()
{
    int i,n,min,minn,temp;
    while(cin>>n)
    {
        if(n==0)break;
        min=9999;minn=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<min)
            {
                min=a[i];
                minn=i;
            }
        }
        temp=a[minn];
        a[minn]=a[0];
        a[0]=temp;
        for(i=0;i<n;i++)
            if(i==0) cout<<a[i];
            else cout<<" "<<a[i];
        cout<<endl; 
        
        
    }    
    return 0;
}
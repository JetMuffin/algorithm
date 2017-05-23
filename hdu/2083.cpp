/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10867262
*/

#include<iostream>
#include<algorithm>
using namespace std;
int l[501];
int main()
{
    int n,i,mid,sum=0,T;
    cin>>T;
    while(T--)
    {
        sum=0;
        cin>>n;
        for(i=0;i<n;i++)
        cin>>l[i];
        sort(l,l+n);
        mid=l[(n-1)/2];
        for(i=0;i<n;i++)
            if(mid>l[i])
                sum+=(mid-l[i]);
            else 
                sum+=(l[i]-mid);
        cout<<sum<<endl;    
    }
} 
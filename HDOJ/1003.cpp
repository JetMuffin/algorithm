/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10816616
*/

#include <iostream>
using namespace std;
int a[100001];
int main()
{
    int T,n,i,m=0,k=0,MAX,sum,temp=0;
    cin>>T;
    for(int j=0;j<T;j++)
    {
        cin>>n;
        m=0;k=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        MAX=-20000;temp=0;sum=0;
        for(i=0;i<n;i++)
        { 
        sum+=a[i];
        if(sum>MAX) 
            {
                MAX=sum;    
                k=i;
                m=temp;
            }
        if(sum<0) {
            sum=0;
            temp=i+1;        
        }
        
    }
        if(j!=0) cout<<endl;
        cout<<"Case "<<j+1<<":"<<endl;
        cout<<MAX<<" "<<m+1<<" "<<k+1<<endl;
    }    
} 
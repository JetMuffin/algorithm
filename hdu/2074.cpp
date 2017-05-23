/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10904079
*/

#include<iostream>
using namespace std;
int main()
{
    int i,j,k=0,n;
    char c[2];
    while(cin>>n)
    {
        if(k==1) cout<<endl;
        k=1;
            if(n%4==1)
        cin>>c[0]>>c[1];
    else 
        cin>>c[1]>>c[0];
    if(n==1)
        {cout<<c[0]<<endl;continue;}
    for(i=1;i<=(n+1)/2;i++)
    {
        if(i==1)
        {
            for(j=1;j<=n;j++)
            {
                if(j==1||j==n)
                    cout<<" ";
                else cout<<c[(n+1)%2];
            }
            cout<<endl;
        }
        else if(i==(n+1)/2)
        {
            for(j=1;j<=n;j++)
                cout<<c[(j+1)%2];
            cout<<endl;
        }
        else{
            for(j=1;j<=i;j++)
            {
                if(j%2==0) cout<<c[1];
                else cout<<c[0];
            }
        for(j=i+1;j<=n-i;j++)
            {
                if(i%2==0)    cout<<c[1];
                else cout<<c[0]; 
            }
        for(j=n-i+1;j<=n;j++)
            {
                if(j%2==0) cout<<c[1];
                else cout<<c[0];
            }
        cout<<endl;
        }

    }
    for(i=(n+1)/2-1;i>=1;i--)
    {
        if(i==1)
        {
            for(j=1;j<=n;j++)
            {
                if(j==1||j==n)
                    cout<<" ";
                else cout<<c[(n+1)%2];
            }
            cout<<endl;
        }
        else if(i==(n+1)/2)
        {
            for(j=1;j<=n;j++)
                cout<<c[(j+1)%2];
        }
        else{
                for(j=1;j<=i;j++)
                {
                    if(j%2==0) cout<<c[1];
                    else cout<<c[0];
                }
            for(j=i+1;j<=n-i;j++)
                {
                    if(i%2==0)    cout<<c[1];
                    else cout<<c[0]; 
                }
            for(j=n-i+1;j<=n;j++)
                {
                    if(j%2==0) cout<<c[1];
                    else cout<<c[0];
                }
                cout<<endl;
            }
        }
    }

    return 0;
} 
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10856770
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    int i,j,k,count;
    int c1[51],c2[51],a[27];   
    cin>>n;
    while(n--)
    {
        count=0;
        for(i=1;i<=26;i++)
            cin>>a[i];
        for(i=0;i<=51;i++)
        {
            c2[i]=0; 
            if(i<=a[1])
                c1[i]=1;
            else c1[i]=0;
        }
        for(i=2;i<=26;i++)   
        {
            for(j=0;j<=50;j++) 
                for(k=0;j+k<=50&&k<=a[i]*i;k+=i)  
                    c2[j+k]+=c1[j];  
            for(j=0;j<=50;j++)
            {
                c1[j]=c2[j];    
                c2[j]=0;   
            }
        }
        for(i=1;i<=50;i++) 
        {
        count+=c1[i];
        
        }
        cout<<count<<endl;
        
    }
    return 0;
}
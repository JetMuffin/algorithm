/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10856483
*/

#include<iostream>
using namespace std;
int main()
{
    int i,j=0,m,sum=0,n,max=-9999,min=9999;
    double score;
    while(cin>>n>>m)
    {
        for(i=1;i<=n;i++)
        {
            sum+=2*i;
            j++;

            if(i==n&&j<m)
            {
                sum/=j;
                cout<<" "<<sum<<endl;
                j=0;sum=0;
            }
            if(j==m)
                {    
                    sum/=m;
                    if(i==m) cout<<sum;
                    else cout<<" "<<sum; 
                    if(i==n) cout<<endl;
                    sum=0;j=0;
                }
            
        }
    }
} 
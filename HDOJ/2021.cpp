/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10868628
*/

#include<iostream>
using namespace std;
int main()
{
    int n,m,i,count;
    int v[101];
    while(cin>>n&&n!=0)
    {
            count=0;
    for(i=0;i<n;i++)
        cin>>v[i];
    for(i=0;i<n;i++)
    {
        m=v[i];
        while(m!=0)
        {
            if(m>=100)
            {
                count++;
                m-=100;
            }
            else if(m>=50)
            {
                count++;
                m-=50;
            }
            else if(m>=10)
            {
                count++;
                m-=10;
            }
            else if(m>=5)
            {
                count++;
                m-=5;
            }
            else if(m>=2)
            {
                count++;
                m-=2;
            }
            else if(m>=1)
            {
                count++;
                m-=1;
            }
        }
    }
    cout<<count<<endl;
    }

} 
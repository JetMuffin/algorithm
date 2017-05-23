/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10831325
*/

#include<iostream>
using namespace std;
int main()
{
    int n,u,d,t,m;
    while(cin>>n>>u>>d&&n!=0)
    {
        t=0;m=0;
        while(m+u<n)
        {
            m+=u;
            t++; 
            m-=d;
            t++;    
        }
        t++;
        cout<<t<<endl;
    }
    return 0;
}
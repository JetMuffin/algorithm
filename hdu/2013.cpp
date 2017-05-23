/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10856362
*/

#include<iostream>
using namespace std;
int main()
{
    int i,j,x,y,sum=1;
    while(cin>>x)
    {
        for(i=1;i<x;i++)
        {
            sum++;
            sum*=2;
        }        
        cout<<sum<<endl; 
        sum=1;
    }
} 
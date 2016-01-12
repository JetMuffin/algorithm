/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10808155
*/

#include<iostream>
using namespace std;
int main()
{
    int a,k;
    while(cin>>a)
    {
        for(k=1;k<66;k++)
            if((a*k+18)%65==0) 
            {
                cout<<k<<endl;
                break;
            }
        if(k==66) cout<<"no"<<endl;
    }
} 
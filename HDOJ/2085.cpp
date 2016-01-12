/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10867300
*/

#include<iostream>
using namespace std;
__int64 h[34],l[34]; 
int main()
{
    int i,n,j;
    h[0]=1;
    l[0]=0;
    for(i=1;i<=33;i++)
    {
        h[i]=h[i-1]*3+l[i-1]*2;
        l[i]=h[i-1]+l[i-1];
    }    
    while(cin>>n&&n!=-1)
    {
        cout<<h[n]<<", "<<l[n]<<endl;
    }
    return 0;
}
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10924641
*/

#include<iostream>
using namespace std;
#include<math.h>
int main()
{
    int m,n,j;
    double i;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        i=(-n+sqrt((double)(n*n-4*m)))/2;
        if(floor(i)==ceil(i))  cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }    
    return 0;
}
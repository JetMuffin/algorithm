/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10815562
*/

#include<iostream>
using namespace std;
int main()
{
    int ans[10][4]={0,0,0,0,1,1,1,1,2,4,8,6,3,9,7,1,4,6,4,6,5,5,5,5,6,6,6,6,7,9,3,1,8,4,2,6,9,1,9,1};
    __int64 b;
    int a,last,k;
     while(cin>>a>>b)
     {
        last=a%10;
        k=b%4;
        if(k==0)k+=4;
        cout<<ans[last][k-1]<<endl;
     }    

    return 0; 
}
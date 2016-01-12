/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10868695
*/

#include<iostream>
using namespace std;
int main()
{
    __int64 A,B;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>A>>B;
        if(A%B==0)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10815096
*/

#include<iostream>
using namespace std;
int main()
{
    int N,a,sum=0;
    while(cin>>N&&N!=0)
        {
            for(int i=0;i<N;i++)
            {
                cin>>a;
                sum+=a;
            }
            cout<<sum<<endl;
            sum=0;
        }
    return 0;
} 
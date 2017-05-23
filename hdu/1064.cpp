/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10780523
*/

#include<iostream>
using namespace std;
int main()
{
    double sum=0,a;
    for(int i=0;i<12;i++)
        {
            cin>>a;
            sum+=a;
        }
        cout<<"$"<<sum/12.0<<endl;
        
    return 0;
} 
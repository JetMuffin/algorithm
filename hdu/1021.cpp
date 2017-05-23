/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10815373
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n%8==2||n%8==6) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
} 
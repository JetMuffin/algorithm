/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11654300
*/

#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        long long a;
        int ans;
        cin>>ans;
        for(int i=1;i<n;i++)
        {
            cin>>a;
            ans ^= a;
        }
        if(ans) puts("Win");
        else puts("Lose");
    }
}
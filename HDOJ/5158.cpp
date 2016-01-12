/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=12816412
*/

#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        printf("%d\n",((m%n-1)+n)%n);
    }
}
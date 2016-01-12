/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13936330
*/

#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
        n*(n+1)/2&1?puts("N"):puts("Y");
}
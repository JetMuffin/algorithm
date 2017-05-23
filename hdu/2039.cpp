/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10917944
*/

#include <stdio.h>
int main()
{
    int n;
    double a,b,c;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%lf %lf %lf",&a,&b,&c);
            if((a+b>c) && (b+c>a) && (a+c>b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
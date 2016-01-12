/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10770639
*/

#include <stdio.h>

int main()
{
    int n;
    __int64 sum = 0;
    
    while (scanf("%d", &n) != EOF)
    {
        sum = (n % 2) == 0 ? ((1 + n) * (n / 2)) : ((1 + n) * (n / 2) + n / 2 + 1);
        printf("%I64d\n", sum);
        printf("\n");
    }
    
    return 0;
}
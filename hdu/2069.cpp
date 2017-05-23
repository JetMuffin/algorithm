/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10904259
*/

#include<stdio.h>
int main()
{
    int i,j,k,l;
    int n,t;
    while (scanf("%d",&n)!=EOF)
    {
        t=0;
        for (int i=0;i*50<=n;i++)
            for (int j=0;j*25<=n;j++)
                for (int k=0;k*10<=n;k++)
                    for (int l=0;l*5<=n;l++)
                        if (n-i*50-j*25-k*10-l*5>=0&&i+j+k+l+n-i*50-j*25-k*10-l*5<=100)
                        t++;
        printf("%d\n",t);
    }
}
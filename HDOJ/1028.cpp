/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10796781
*/

#include<stdio.h>
int main()
{
    int n;
    int i,j,k;
    int c1[1000],c2[1000];  
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<=n;i++)
        {
            c1[i]=1;c2[i]=0;    
        }
        for(i=2;i<=n;i++)  
        {
            for(j=0;j<=n;j++)
                for(k=0;j+k<=n;k+=i)  
                    c2[j+k]+=c1[j];   
            for(j=0;j<=n;j++)
            {
                c1[j]=c2[j];   
                c2[j]=0;    
            }
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}
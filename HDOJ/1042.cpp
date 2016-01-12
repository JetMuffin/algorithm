/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10775016
*/

#include<stdio.h>
#include<string.h>
int s[100001]={0};
int main()
{
    int n,i,j,t,k;
    while(scanf("%d",&n)==1)
    {
        memset(s,0,sizeof(s));
        if(n==0)
        {
            printf("1\n");
            continue;
        }
        s[0]=1; 
        for(t=0,k=0,i=2;i<=n;i++)
            for(j=0;j<=t;j++)
            {    
                s[j]=s[j]*i;
                s[j]+=k;
                k=s[j]/10;
                s[j]%=10;
                if(j==t)
                {
                    t+=4;
                    break;
                }
            }
        for(k=0,i=t;i>=0;i--)
        {
            if(s[i]!=0)
            {
                for(j=i;j>=0;j--)
                    printf("%d",s[j]);
                printf("\n");
                break;
            }
            
        }
            
    }    
    
    return 0;
}
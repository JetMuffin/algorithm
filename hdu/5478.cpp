/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14945226
*/

#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  
#include <time.h>  
typedef long long LL;  
LL C,k1,k2,b1;  
LL poww(LL a,LL b)  
{  
    LL res=a,ans = 1 ;  
    while(b)  
    {  
        if(b&1) ans = (ans*res)%C ;  
        b>>=1 ;  
        res= (res*res)%C ;  
    }  
    return ans%C;  
}  
int main()  
{  
    LL tot = 1;  
    while(scanf("%lld %lld %lld %lld",&C,&k1,&b1,&k2)!=EOF)  
    {  
        printf("Case #%d:\n",tot++);  
        LL s = 0;  
        for(LL i = 1; i<C; i++) ///枚举a  
        {  
            bool ok = true;  
            LL  b = C - poww(i,k1+b1); ///求b  
            if(b<=0) continue;  
            for(LL n =3000 ; n<=3500; n++) ///筛选  
            {  
                LL rr = n;  
                if(((LL)poww(i,k1*rr+b1)+(LL)poww(b,k2*rr-k2+1))%C!=0)  
                {  
                    ok = false;  
                    break;  
                }  
            }  
            if(ok)  
            {  
                printf("%lld %lld\n",i,b);  
                s++;  
            }  
        }  
        if(!s) ///无解！  
        {  
            puts("-1");  
        }  
    }  
    return 0;  
}  
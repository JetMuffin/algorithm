/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11188643
*/

#include<iostream>
#define eps 1e-8
using namespace std;

double dp[30], p;

int main()
{
        while (~scanf("%lf",&p)){
                double ans = 0;
                dp[1] = 1/p;
                dp[2] = 1+((1-p)*(1+dp[1]))/p;
                ans = (dp[1]+dp[2])*2;
                for (int i=3;i<=20;i++){
                    dp[i] = 1 + ((1-p)*(1+dp[i-2]+dp[i-1])) /p;
                    ans += dp[i]*2;
                }
                ans -= dp[20];
                printf("%.6lf\n",ans);
        }
}
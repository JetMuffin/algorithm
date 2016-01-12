/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=12816744
*/

#include <iostream>
#include <cstdio>
using namespace std;
int cnt = 0;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cnt++;
        double x;
        int b;
        scanf("%lf%d",&x,&b);
        double p = 1.0;
        for(int i = 0; i < b; i++)
            p *= (1 - 1/x);
        double ans = (1 - p) * (x + 1) * x / 2;
        printf("Case #%d: %.3f\n",cnt,ans);
    }
}
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11942920
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
double p[50005];
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(p,0,sizeof(p));
        int n,k;
        cin>>n>>k;
        for(int i = 1;i<=n;i++)
            cin>>p[i];
            
        if(n==k)
        {
            printf("%.9f\n",0); 
            continue;    
        } 
        sort(p+1,p+n+1);
        double sum = 0;
        double sqrsum = 0;
         for(int i = 1;i<=n-k;i++)
         {
                sum += p[i];
                sqrsum += p[i] * p[i];
         }
        double avg  = sum/(double) (n-k);
        double min = sqrsum + (n-k)*avg*avg - 2*sum*avg;
       // cout<<sum<<" "<<sqrsum<<" "<<avg<<" "<<min<<endl;
        int flag = 0;
        for(int i = 1 ;i <= k; i++)
        {
                sum = sum + p[n-k+i] - p[i];
                sqrsum = sqrsum + p[n-k+i]*p[n-k+i] - p[i]*p[i];
                avg = sum/(double) (n-k);
                double now  = sqrsum + (n-k)*avg*avg - 2*sum*avg;
              //     cout<<i<<" "<<sum<<" "<<sqrsum<<" "<<avg<<" "<<min<<endl;
                if(now < min)
                {
                    min = now;
                    flag = i;
                }
        }
        printf("%.10f\n",min);
}
}
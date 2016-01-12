/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11496203
*/

#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int sc,n;
        cin>>sc>>n;
        int y=sc*n;
        double ans1=0.0l,ans2=4.0l;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n-i;j++)
                for(int k=0;k<=n-i-j;k++)
                    for(int l=0;l<=n-i-j-k;l++)
                        for(int m=0;m<=n-i-j-k-l;m++)
                        {
                            if(i+j+k+l+m==n)
                            {
//                                 printf("%d %d %d %d %d\n", i, j, k, l, m);
                                int sum1 = i*100+j*84+k*79+l*74+m*69;
                                int sum2 = i*85+j*80+k*75+l*70+m*60;
                                double gpa = (i*4.0+j*3.5+k*3.0+l*2.5+m*2.0)/n;
                                
                                if(y>=sum2&&y<=sum1)
                                {
                                    if(gpa>ans1) ans1=gpa;
                                    if(gpa<ans2) ans2=gpa;
                                }
                            }
                        }
        printf("%.4lf %.4lf\n",ans2,ans1);
    }
} 
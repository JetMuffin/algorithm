/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10856374
*/

#include<iostream>
using namespace std;
int main()
{
    int i,m,sum=0,n,max=-9999,min=9999;
    double score;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>m;
            if(m>max)max=m;
            if(m<min)min=m;
            sum+=m;
        }
        sum-=max;
        sum-=min;
        score=sum/(double)(n-2);
        printf("%.2lf\n",score);
        sum=0;
        max=-9999;min=9999;
    }
} 
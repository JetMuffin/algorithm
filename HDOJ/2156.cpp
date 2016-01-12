/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10910691
*/

#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    double sum;
    while(cin>>n&&n!=0)
    {
        sum=0;
        sum+=n;
        j=n-1;
        for(i=2;i<=n;i++)
        {            
            sum+=((1/(double)i)*2*j);    
            j--;    
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
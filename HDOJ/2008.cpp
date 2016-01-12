/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10854935
*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b,c,n;
    double i;
    while(cin>>n&&n!=0)
    {
        a=b=c=0;
        for(int j=0;j<n;j++)
        {
            cin>>i;
            if(i==0) b++;
            else if(i<0)a++;
            else c++;
        
        }
        printf("%d %d %d\n",a,b,c);
    }        
    return 0;    
} 
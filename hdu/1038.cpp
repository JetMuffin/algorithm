/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10780651
*/

#include<iostream>
using namespace std;
#define pi 3.1415927
int main()
{
    int N=0;
    int r;
    double t,d,m,v,h;
    while(cin>>d){
        cin>>r>>t;
        m=2*pi*(d/2)*r/12/5280;
        h=t/60/60;
        v=m/h;
        N++;
        if(m!=0&&v!=0)
            printf("Trip #%d: %.2f %.2f\n",N,m,v);
    }
    return 0;
} 
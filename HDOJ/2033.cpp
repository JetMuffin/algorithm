/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10910514
*/

#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,e,f,g,h,i,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>e>>f;
        i=c+f;
        h=b+e;
        g=a+d;
        if(i>=60)
        {
            i-=60;
            h++;
        }
        if(h>=60)
        {
            h-=60;
            g++;
        }    
        cout<<g<<" "<<h<<" "<<i<<endl;
    }
} 
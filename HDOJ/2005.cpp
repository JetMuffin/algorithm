/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10854899
*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b,c,day,flag;
    while(scanf("%d/%d/%d",&a,&b,&c)!=EOF)
    {    
        if(a%400==0||(a%4==0&&a%100!=0))
            flag=1;
        else flag=0;
        switch(b)
        {
            case 1:day=0;break;
            case 2:day=31;break;
            case 3:day=59;break;
            case 4:day=90;break;
            case 5:day=120;break;
            case 6:day=151;break;
            case 7:day=181;break;
            case 8:day=212;break;
            case 9:day=243;break;
            case 10:day=273;break;
            case 11:day=304;break;
            case 12:day=334;break;
            default:break;
        }
        day+=c;
        if(flag&&b>2)day++;
        cout<<day<<endl;
    }
            
} 
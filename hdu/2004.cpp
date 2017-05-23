/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10854871
*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int  a;
    while(cin>>a)
    {
        if (a<0)
            cout<<"Score is error!"<<endl;
        else if(a<60)
            cout<<"E"<<endl;
        else if(a<70)
            cout<<"D"<<endl;
        else if(a<80)
            cout<<"C"<<endl;
        else if(a<90)
            cout<<"B"<<endl;
        else if(a<=100)
            cout<<"A"<<endl;
        else 
            cout<<"Score is error!"<<endl;
    }
            
} 
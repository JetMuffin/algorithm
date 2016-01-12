/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10780549
*/

#include<iostream>
using namespace std;
int main()
{
    int a[3],i;
    for(i=0;i<3;i++)
        {
            cin>>a[i];

        }
    for(i=0;i<3;i++){
        if(a[i]<168) {
            cout<<"CRASH "<<a[i]<<endl;
            break;
        }
    }

        if(i==3) cout<<"NO CRASH"<<endl;
        
    return 0;
} 
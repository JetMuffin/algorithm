/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10803480
*/

#include<iostream>
using namespace std;
int main()
{
    int year,flag,count,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>year>>count;
    while(count>0)
    {    
        if(year%400==0) count--;
        else if(year%4==0&&year%100!=0) count--;
        year++;
    }

    cout<<year-1<<endl;
} 
return 0;
    }
    
    

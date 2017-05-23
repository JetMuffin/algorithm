/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10803855
*/

#include<iostream>
using namespace std;
#define PI 3.1415927
int main()
{
    double n,area;    
    while(cin>>n)
    {
        area=4/3.0*PI*n*n*n;
        printf("%.3f\n",area);
    } 
}
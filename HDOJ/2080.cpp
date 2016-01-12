/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11872482
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <ctime>
using namespace std;

#define LL long long
#define ULL unsigned long long
//#define mod 1000000007
#define eps 1e-8
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define RREP(i,a,b) for(int i = b; i > a ; --i)
#define RE freopen("in.txt","r",stdin)
#define WE freopen("out.txt","w",stdout) 
#define PI 3.141592654
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        double x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
           double a=x1*x1+y1*y1;
        double b=x2*x2+y2*y2;
        double c=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        double t=(a+b-c)/(2*sqrt(a)*sqrt(b));
        double arc=acos(t);
        arc=arc*180.0/PI;
        printf("%.2f\n",arc);
    }
} 
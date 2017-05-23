/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11873332
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

int do10(int n)
{
    int sum=0;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int do16(int n)
{
    int sum=0;
    while(n)
    {
        sum+=n%16;
        n/=16;
    }
    return sum;
}
int do12(int n)
{
    int sum=0;
    while(n)
    {
        sum+=n%12;
        n/=12;
    }
    return sum;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(!n) break;
        if(do10(n)==do12(n)&&do12(n)==do16(n))
            cout<<n<<" is a Sky Number."<<endl;
        else
            cout<<n<<" is not a Sky Number."<<endl;
    }
} 
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11872854
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

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        int flag=0;
        if(a==0&&b==0)
            break;
        long tmp = a*100;
        for(int i=0;i<100;i++)
        {
            if((tmp+i)%b==0)
            {
                if(!flag) 
                {
                    if(i<10)
                        cout<<"0"<<i;
                    else
                        cout<<i;
                    flag = 1;    
                }    
                else
                    if(i<10)
                        cout<<" 0"<<i;
                    else
                        cout<<" "<<i;
            }
        }
        cout<<endl;
    }
} 
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11596374
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
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define RREP(i,a,b) for(int i = b; i >= a ; --i)
#define RE freopen("in.txt","r",stdin)
#define WE freopen("out.txt","w",stdout) 

#define maxn 100010
int a[maxn],vis[maxn];
 
int main()
{
    //RE;
    int n;
    while(cin>>n)
    {
        int ok=0;
        memset(vis,0,sizeof(vis));
        REP(i,1,n)
            cin>>a[i];
        REP(i,1,n)
        {
            int tmp=i;
            
            if(!vis[tmp]) cout<<"(";
            while(!vis[tmp])
            {
                int t=tmp;
                vis[tmp]=1;
                tmp=a[tmp];
                if(vis[tmp])
                {
                    cout<<t;
                    ok=1;
                }
                else
                {    
                    cout<<t<<" ";
                }
            }
            if(ok) 
            {
                cout<<")";
                ok=0;
            }
        }
        cout<<endl;
    }
} 
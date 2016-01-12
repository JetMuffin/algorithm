/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=12235970
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
//#define WE freopen("out.txt","w",stdout) 

const int maxn = 10000;
int notprime[maxn+1];
int prime[maxn+1];
int cnt = 0; 
void init()
{
    memset(notprime,0,sizeof(prime));
    notprime[0] = notprime[1] = true;
    for(int i = 2; i < maxn; i++)
    {
        if(!notprime[i])
        {
            if(i > maxn / i) continue;
            for(int j = i * i; j < maxn; j+=i)
                notprime[j] = 1;
        } 
    } 
} 
void getPrime()
{
    for(int i = 2; i < maxn; i++)
    {
        if(!notprime[i])
        {
            prime[cnt++] = i;
        }
    } 
}
int main()
{
    init();
    getPrime();
    int n;
    while(cin>>n)
    {
        int ans = 0;
        for(int i = 0;prime[i] <= n / 3;i++)
            for(int j = i ;n-prime[i]-prime[j]>=prime[j];j++)
            {
                
                int tmp = n - prime[i] - prime[j];
                if(!notprime[tmp])
                {
                    ans++;
                }
            }
        cout<<ans<<endl;
    }
} 
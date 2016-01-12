/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13930295
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
#define MP make_pair

#define mod 1000000007
#define eps 1e-8
#define pi acos(-1.0)
#define inf 0x3fffffff
#define maxn 100005
int f[maxn];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    
    int n;
    
    while(~scanf("%d",&n)&&n){
        for(int i = 0; i < n; i++)
            scanf("%d",f+i);
        int mx = -1,ml=0,mr=0,l = 0,r = 0,sum = 0;
        for(int i = 0 ; i < n; i++) {
            sum += f[i];
            if(sum >= 0){
                r++;
                if(sum > mx){
                    mx = sum;
                    mr = r - 1;
                    ml = l;
                }
            }else{
                sum = 0;
                r = l = i+1;                
            }
    
        }
        if(mx < 0){
            printf("%d %d %d\n",0,f[0],f[n-1]);
        }else{
            printf("%d %d %d\n",mx,f[ml],f[mr]);
        }
        
    }
} 
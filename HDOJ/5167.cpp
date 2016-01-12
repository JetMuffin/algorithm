/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=12878343
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1000000000
#define LL long long
LL f[100];
int vis[100];
int cnt;
int flag;
LL now = 1;
LL n;
vector<LL> v;
vector<LL>::iterator it;
void dfs(int t,LL val)
{
//    cout<<t<<" "<<val<<endl; 
    v.push_back(val);
    if(t >= cnt)
        return;
    for(int i = t; i < cnt; i++)
    {
        LL tmp = val * f[i];
        if(tmp > INF)
            break;
        dfs(i,tmp);
    }
}
void init()
{
    f[0] = 0;
    f[1] = 1;
    cnt = 2;
    for(int i = 2;f[i] < 100;i++)
    {
        f[i] = f[i-1] + f[i-2];
        if(f[i] > INF) break;
        cnt++;
    }    
//    cnt = 5;
    v.push_back(0);    
    dfs(3,1);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
int main()
{
    init();
    
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        flag = 0;
        memset(vis,0,sizeof(vis));
        it = lower_bound(v.begin(),v.end(),n);
        if( it!= v.end() && *it== n) flag = 1;
        if(!flag)
            puts("No");
        else
            puts("Yes");
    }
} 
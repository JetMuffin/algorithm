/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=12877482
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int f[1005];
int ans[2];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        memset(f,0,sizeof(f));
        memset(ans,0,sizeof(ans));
        int max;
        for(int i = 0 ; i < n; i++)
        {
            int x;
            max = -1;
            cin>>x;
            f[x]++;
        }
        int cnt = 0;
            for(int i = 1 ; i <= n+2; i++)
            {
                if(!f[i])
                    ans[cnt++] = i;
            }
            sort(ans,ans+2);
            cout<<ans[0]<<" "<<ans[1]<<endl;            
    }
} 
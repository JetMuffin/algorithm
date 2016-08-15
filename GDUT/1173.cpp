#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>

using namespace std;
#define LL long long

LL d[1000009], g[1000009];

int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d", &d[i]);

        g[0] = d[0];
        for(int i=1; i<n; i++)
            g[i] = g[i-1] + d[i];
        stack<int> s;

        LL ans = 0;
        for(int i=0; i<n; i++)
        {
            if(s.empty())
            {
                s.push(i);
                continue;
            }
            int t;
            while(!s.empty())
            {
                t = s.top();
                if(d[t] > d[i])
                    break;
                s.pop();
            }

            if(s.empty())
                ans += (i-t-1)*d[t]-(g[i-1]-g[t]);

            s.push(i);
        }
        if(!s.empty())
        {
            int i = s.top();
            s.pop();
            while(!s.empty())
            {
                int t = s.top();
                s.pop();
                ans += (i-t-1)*d[i]-(g[i-1]-g[t]);
                i = t;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
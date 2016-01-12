/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13933699
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

char s[105];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    
    while(gets(s)){
        if(s[0] > 'Z')
            s[0] += 'A' - 'a';
        int len = strlen(s);  
        for(int i = 0; i+1<len;i++)
            if(s[i] == ' ')
                if(s[i+1] > 'Z')
                    s[i+1] += 'A' - 'a';
        cout<<s<<endl;
        memset(s,0,sizeof(s));
    }
} 
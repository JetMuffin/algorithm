/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13933726
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
int num(char c){
    if(c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}
int al(char c){
    if( c >= 'a' && c <= 'z')
        return 1;
    if(c>='A' && c<='Z')
        return 1;
    return 0;
}
int check(){
    if(!(al(s[0])||s[0] == '_'))
        return 0;
    int len = strlen(s);
    for(int i = 1 ; i < len; i++)
        if(!num(s[i]) && !al(s[i]) && s[i]!='_')
            return 0;
    return 1;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(s);
        //cout<<s<<endl;
        if(check())
            puts("yes");
        else
            puts("no");    
    }
} 
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13933788
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
#include <set>
#include <ctime>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define MP make_pair

#define mod 1000000007
#define eps 1e-8
#define pi acos(-1.0)
#define inf 0x3fffffff

set <string> win;
set <string> lose;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    
    int n;
    while(cin>>n&&n){
        win.clear();
        lose.clear();
        for(int i = 0 ; i < n; i++){
            string x,y;
            cin>>x>>y;
            win.insert(x);
            win.insert(y);
            lose.insert(y);
        }
        if(win.size()-lose.size()!= 1)
            puts("No");
        else
            puts("Yes");
    }
} 
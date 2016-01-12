/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13933685
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

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    
    int t;
    scanf("%d",&t);
    while(t--){
        char c;
        int n;
        cin>>c>>n;
        int ans;
        if(c > 'Z')
            ans = 'a' - 1 - c; 
        else
            ans = c - 'A' + 1;
        cout<<ans+n<<endl;
    }
} 
/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13933895
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
#include<iomanip>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define MP make_pair

#define mod 1000000007
#define eps 1e-8
#define pi acos(-1.0)
#define inf 0x3fffffff


struct p{
    char name[10];
    char sc[13][10];
    int t,s;
}a[6];
int work(char *s,int i,int m){
    int res = 0;
    if(s[0] == '-' || s[0] =='0')
        return 0;
    int len = strlen(s);
    int l = 0,r = 0;
    for(;l<len&&s[l]!='(';l++);
    for(;r<len&&s[r]!=')';r++);
    if(l!= len){
        int tmp = 1;
        int score = 0;
        for(int i = l-1;i>=0;i--){
            score += tmp*(s[i] - '0');
            tmp*=10;
        }
        res += score; 
        tmp = 1;
        int fan = 0;
        for(int i = r-1;i>l;i--){
            fan += tmp*(s[i] - '0');
            tmp*=10;
        }        
        res += m*fan;
    }else{
        int tmp = 1;
        int score = 0;
        for(int i = len-1;i>=0;i--){
            score += tmp*(s[i] - '0');
            tmp*=10;
        }
        res += score;
    }
    return res;    
}
int cmp(p x, p y){
    if(x.t != y.t)
        return x.t > y.t;
    else
        return x.s<y.s;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        //cout<<n<<" "<<m<<endl;
        memset(a,0,sizeof(a));
        for(int i = 0 ; i < 6; i++){
            scanf("%s",a[i].name);
            for(int j = 0 ; j < n; j++){
                scanf("%s",a[i].sc[j]);
            }
        }
        for(int i = 0 ; i < 6; i++){
            for(int j = 0 ; j < n; j++){
                int score = work(a[i].sc[j],i,m);
                if(score){
                    a[i].t ++;
                    a[i].s += score;
                }
            }
        }
        sort(a,a+6,cmp);
        for(int i = 0 ; i < 6; i++){
            printf("%-10s %2d %4d\n",a[i].name,a[i].t,a[i].s);
        }
    }
} 
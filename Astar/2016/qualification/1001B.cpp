#include <cstring>  
#include <iostream>  
#include <cstdio>
using namespace std;
#define LL long long
#define M 9973
char s[100010];
LL a[100010];
void exp_gcd( LL a ,LL b,LL &x,LL &y) {  
     if( b == 0 ) {  
         x = 1;  
         y = 0;  
     }  
     else {  
          exp_gcd( b,a%b,x,y );  
          LL t;  
          t = x;  
          x = y;  
          y = t - a/b*y;  
     }  
}  

inline LL getNN(LL x) {  
        LL now , t;  
        exp_gcd( x, M,now,t );  
        return (now%M+M)%M;  
}

void init() {
    int len = strlen(s);
    a[0] = (LL)(int(s[0]) - 28);
    for(int i = 1; i < len; i++) {
        LL t = (LL)(int(s[i])-28);
        a[i] = (a[i-1]*t)%M;
    }
}

int main() {    
    int n, l ,r;
    while(~scanf("%d", &n)) {
        scanf("%s", s);
        char len = strlen(s);
        init();
        for(int i = 0 ; i < n ; i++) {
            scanf("%d%d", &l, &r);
            if (l == 1) {
                printf("%lld\n", a[r-1]);
                continue;
            }
            LL x = getNN(a[l-2]);
            LL ans = x*a[r-1]%9973;
            printf("%lld\n", ans);
        }
    }
}  
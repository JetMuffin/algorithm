#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define LL long long
using namespace std;

LL a,b,n;
vector<LL> v;

LL solve(LL x,LL n){
    v.clear();
    LL i,j;
    for(i = 2 ; i * i <= n; i++)     
        if(n % i == 0){
            v.push_back(i);
            while(n % i == 0)
                n /= i;
        }
    if(n > 1)
        v.push_back(n);

    LL sum = 0, val, cnt;
    for(i = 1; i < (1<<v.size()); i++){  
        val = 1;
        cnt = 0;
        for(j = 0; j < v.size(); j++)
            if(i &(1<<j)){       
                val*=v[j];
                cnt++;
            }
        if(cnt&1)       
            sum += x/val;
        else
            sum -= x/val;
    }
    return x-sum;
}

int main(){
    int t, cas = 0;
    scanf("%d", &t);
    while(t--){
        cas ++;
        scanf("%lld %lld %lld", &a, &b, &n);
        printf("%lld\n", solve(b,n) - solve(a-1,n));
    }
    return 0;
}
#include <iostream>
using namespace std;

#define maxn 1<<20
int n,k;
int c[maxn],p[maxn];

int lowbit(int x){
    return x&-x;
}

void insert(int x,int t){
       while(x<maxn){
          c[x]+=t;
          x+=lowbit(x);    
       }
}
int find(int k){
    int cnt=0,ans=0;
    for(int i=20;i>=0;i--){
        ans+=(1<<i);
        if(ans>=maxn || cnt+c[ans]>=k)ans-=(1<<i);
        else cnt+=c[ans];
    }
    return ans+1;
}
void update(int x,int d){
    for(;x<=maxn;x+=lowbit(x))
        c[x]+=d;
}

int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &p[i]);
        }
        for(int i = 1; i <= n; i++){
            insert(i,1);
        }
        for(int i = n; i >= 1; i--){
            int k = n - p[i];
            int t = find(k);
            update(t, -1);
            cout<<t<<endl;
        }
    }
    return 0;
}
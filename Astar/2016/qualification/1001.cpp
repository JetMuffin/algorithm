#include<cstring>  
#include<iostream>  
using namespace std;

#define M 200010  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
/*left,right,root,middle*/  
  
int sum[M<<4];  
char s[M];
  
inline void PushPlus(int rt)  
{  
    sum[rt] = (sum[rt<<1] * sum[rt<<1|1]);  
    if(sum[rt] != 0) {
        sum[rt] = sum[rt]%9973;
    }
}  
  
void Build(int l, int r, int rt)  
{  
    if(l == r)  
    {  
        sum[rt] = int(s[l-1]) - 28;

        // cout<<"sum:"<<sum[rt]<<endl;
        return ;  
    }  
    int m = ( l + r )>>1;  
  
    Build(lson);  
    Build(rson);  
    PushPlus(rt);  
}  
  
int Query(int L,int R,int l,int r,int rt)  
{  
    if( L <= l && r <= R )  
    {  
        return sum[rt];  
    }  
    int m = ( l + r ) >> 1;  
    int ans=1;  
    if(L<=m )  {
        ans=(ans*Query(L,R,lson));  
        if(ans !=0 ) {
            ans = ans%9973;
        }
    }
    if(R>m)  {
        ans=(ans*Query(L,R,rson));
        if(ans != 0) {
            ans = ans %9973;
        }  
    }
  
    return ans;  
}   
int main() {    
    int n, l ,r;
    while(~scanf("%d", &n)) {
        scanf("%s", s);
        char len = strlen(s);

        // for(int i = 0 ; i < len; i++) {
        //     cout<<int(s[i])-28<<endl;
        // }
        Build(1, len, 1);
        // for(int i = 1; i<= len*2; i++) {
        //     cout<<sum[i]<<" ";
        // }
        // cout<<endl;
        for(int i = 0 ; i < n ; i++) {
            scanf("%d%d", &l, &r);
            printf("%d\n", Query(l, r, 1, len, 1)%9973);
        }
    }
}    
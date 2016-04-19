#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long c1[10000], c2[10000];
int a[10000];
int main() {
    int t, cas= 0, n,m;
    scanf("%d", &t);
    while(t--) {
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        cas++;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n+10; i++) {
            c1[i] = 0;
            c2[i] = 0;
        }
        c1[0] = 1;
        for(int i = 0 ; i < n ;i ++) {
            scanf("%d", &a[i]);
            if(a[i] == 0) continue;
            for(int j=0;j <= m;j++)  
            {  
                for(int k=0;k+j<=m;k+=a[i])
                {  
                    c2[k+j]+=c1[j];  
                }  
            }  
              
            for(int j=0;j<=m;j++) {  
                c1[j]=c2[j];  
                c2[j]=0; 
            }              
        }
        for(int i = 0;i <= m; i++)  {  
            c1[i]=1;  
            c2[i]=0;  
        }  
        for(int i = 0;i < n;i++) {  
            if(a[i] == 1 || a[i] == 0) continue;
            for(int j=0;j <= m;j++)  
            {  
                for(int k=0;k+j<=m;k+=a[i])
                {  
                    c2[k+j]+=c1[j];  
                }  
            }  
              
            for(int j=0;j<=m;j++) {  
                c1[j]=c2[j];  
                c2[j]=0; 
            }  
            
        }

        printf("Case #%d: %lld\n",cas, c1[m]);  
    }
}
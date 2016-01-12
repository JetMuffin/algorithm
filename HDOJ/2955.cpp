/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11198570
*/

#include<iostream>
#include<string.h>
using namespace std;
int M[101];
float p[101],f[10001];
int max(int a,int b){return a>b?a:b;} 
int main()
{
//    freopen("in.txt","r",stdin);
    int T,N,sum;
    int i,j;
    float P;
    cin>>T;
    while(T--)
    {
        cin>>P>>N;
        P=1-P;
        sum=0;
        memset(f,0,sizeof(f));
        f[0]=1;
        for(i=0;i<N;i++)
            cin>>M[i]>>p[i];
        for(i=0;i<N;i++)
            {
                sum+=M[i];
                p[i]=1-p[i];
            }
        for(i=0;i<N;i++)
            for(j=sum;j>=M[i];j--)
                f[j]=max(f[j],f[j-M[i]]*p[i]);
//        for(i=0;i<=sum;i++)
//            cout<<f[i]<<" ";
//        cout<<endl;
        for(i=sum;i>=0;i--)
        {
            if(f[i]>P) break;
        }
        cout<<i<<endl;
    }
    return 0;
} 
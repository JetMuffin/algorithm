/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11124924
*/

#include<iostream>
using namespace std;
__int64 h[1000001];
const int  MOD=1000000007;
int extgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=extgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

int main()
{
    int T;
    int n,i,j,x,y;
    h[0]=1;
    for(i=1;i<=1000000;i++)
    {
        h[i]=(4*i-2)%MOD;
        h[i]=(h[i]*h[i-1])%MOD;
        extgcd(i+1,MOD,x,y);
        h[i]=(h[i]*(x+MOD)%MOD)%MOD;
    }
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>n;
        cout<<"Case #"<<i<<":"<<endl;
        cout<<h[n]<<endl;
    }
    return 0;
} 